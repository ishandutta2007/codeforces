#include <bits/stdc++.h>
using namespace std;

struct q{int p, s;}a[1000005];
int N, M, i, j, x, t; string s[1000005], out;
bool cmp(q i,q j){return(i.p<j.p);}

int main(){
	for(scanf("%d",&N),i=0;i<N;i++){
		cin >> s[i]; scanf("%d",&M);
		for(j=0;j<M;j++){
			scanf("%d",&a[t].p);
			a[t++].s = i;
		}
	}
	sort(a, a+t, cmp);
	for(x=1,i=0;i<t;i++){
		while(a[i].p > x){x++; out.push_back('a');}
		if(s[a[i].s].size()+a[i].p > x){
			int dif = s[a[i].s].size()+a[i].p-x;
			out += s[a[i].s].substr(s[a[i].s].size()-dif,dif);
			x = s[a[i].s].size()+a[i].p;
		}
	}
	cout << out << '\n';
	return 0;
}