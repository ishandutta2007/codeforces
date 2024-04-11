#include <bits/stdc++.h>
using namespace std;

class BigNum {
public:
	bitset<2013> val;
	bitset<2013> has;
	BigNum(bitset<2013> res) { val = res; }
	BigNum(vector<int> ten, int ind) {
		reverse(ten.begin(),ten.end());
		for(int i=0;i<80;i++) {
			int rem = 0;
			for(int j=ten.size()-1;j>=0;j--) {
				ten[j]+=rem*10;
				rem = ten[j]&((1<<25)-1);
				ten[j]>>=25;
			}
			for (int j=0;j<25;j++) val[i*25+j]=(rem&(1<<j))>0;
			while (ten.size() && !ten.back()) ten.pop_back();
			if (ten.size()==0) break;
		}
		has[ind] = 1;
	}
	void operator^=(BigNum& o) {
		val^=o.val;
		has^=o.has;
	}
};

int n;
char s[613];
vector<BigNum> basis;
int pos[2013];

bitset<2013> add(BigNum x) {
	for (int i=2012;i>=0;i--) if (x.val[i] && pos[i]!=-1) {
		x^=basis[pos[i]];
	}
	if (!x.val.any()) return x.has;
	int high;
	for (high=2012;!x.val[high];high--);
	pos[high] = basis.size();
	for (BigNum& y: basis) if (y.val[high]) {
		y^=x;
	}
	basis.push_back(x);
	return NULL;
}

int main() {
	for (int i=0;i<2013;i++) pos[i] = -1;
	scanf("%d",&n);
	for (int i=0;i<n;i++) {
		scanf(" %s",&s);
		vector<int> cur;
		for (int j=0;s[j]!='\0';j++) cur.push_back(s[j]-'0');
		bitset<2013> res = add(BigNum(cur,i));
		if (res==NULL) printf("0\n");
		else {
			printf("%d",res.count()-1);
			for (int j=0;j<i;j++) if (res[j]) printf(" %d",j);
			printf("\n");
		}
	}

	return 0;
}