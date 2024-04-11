// wygzgyw
#include <bits/stdc++.h>
using namespace std;
template <typename T> void read(T &t) {
	t=0; char ch=getchar(); int f=1;
	while (ch<'0'||ch>'9') { if (ch=='-') f=-1; ch=getchar(); }
	do { (t*=10)+=ch-'0'; ch=getchar(); } while ('0'<=ch&&ch<='9'); t*=f;
}
template <typename T> void write(T t) {
	if (t<0) { putchar('-'); write(-t); return; }
	if (t>9) write(t/10);
	putchar('0'+t%10);
}
template <typename T> void writeln(T t) { write(t); puts(""); }
#define MP make_pair

int n,x;
int flag;
int lst=-1;
int cnt;
int query(vector<int> S) {
	cnt++;
	if (!flag) { printf("? %d ",(int)S.size()); for (int &a : S) printf("%d ",a); puts(""); fflush(stdout); }
	if (flag) {
		int res=0;
		for (int &a : S) if (x==a) res=1;
		if (lst==0) lst=1;
		else lst=rand()%2;
		if (lst) return res; return res^1;
	}
	char s[20]; scanf("%s",s);
	return s[0]=='Y';
}
void answer(int x) {
	printf("! %d\n",x); fflush(stdout);
	if (flag) { if (x==::x) exit(0); return; }
	char s[20]; scanf("%s",s);
	if (s[1]==')') exit(0);
}
vector<int> vec;
int main() {
	//freopen("1.txt","r",stdin);
	scanf("%d",&n);
	
	srand(time(0));

	flag=0;
	if (flag) x=rand()%n+1;
	
	for (int i=1;i<=n;i++) vec.push_back(i);
	while (1) {
		int m=(int)vec.size();
		if (m<=3) break;
		vector<int> S1,S2;
		int t1=(1<<0)|(1<<1);
		int t2=(1<<0)|(1<<2);
		for (int i=0;i<m;i++) if (i%4==0||i%4==1) S1.push_back(vec[i]);
		for (int i=0;i<m;i++) if (i%4==0||i%4==2) S2.push_back(vec[i]);
		if (query(S1)) t1=(1<<4)-1-t1;
		if (query(S2)) t2=(1<<4)-1-t2;
		vector<int> vec2;
		for (int i=0;i<m;i++) if ((t1&t2)>>(i%4)&1); else vec2.push_back(vec[i]);
		vec.swap(vec2);
	}
	if (flag) cerr<<cnt<<endl;
	int m=(int)vec.size();
	if (m<=2) { for (int &x : vec) answer(x); }
//	for (int &x : vec) printf("%d\n",x);
//	if (flag) printf("x=%d\n",x);
	vector<int> d;
	int a=vec[0],b=vec[1],c=vec[2];
	d.push_back(query({a}));
	d.push_back(query({a}));
	d.push_back(query({b}));
	d.push_back(query({b}));
	d.push_back(query({c}));
	d.push_back(query({c}));
	if (!d[0]&&!d[1]) answer(b),answer(c);
	if (!d[2]&&!d[3]) answer(a),answer(c);
	if (!d[4]&&!d[5]) answer(a),answer(b);
	
	if (d[0]&&d[1]) answer(a);
	if (d[2]&&d[3]) answer(b);
	if (d[4]&&d[5]) answer(c);
	
	
	for (int i=0;i<3;i++) {
		vector<int> v;
		for (int j=0;j<6;j++) {
			if (d[j]^(j/2==i)) v.push_back(j);
		}
		int flag=1;
		for (int j=1;j<v.size();j++) if (v[j-1]+1==v[j]) { flag=0; break; }
		if (flag) answer(i==0?a:i==1?b:c);
	}
	
	return 0;
}