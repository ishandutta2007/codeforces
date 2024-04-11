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
int T,n;
vector<vector<int> > v1,v2;
int d[100],dy[100];
bool chk(vector<int> &A,vector<int> &B) {
	int cnt=0;
	for (int i=0;i<(int)A.size();i++) {
		if (A[i]&&B[i]) {
			cnt++;
			if (A[i]>1&&B[i]>1) return 0;
		}
	}
	return cnt==1;
}
int main() {
	//freopen("1.txt","r",stdin);
	read(T);
	while (T--) {
		read(n);
		for (int i=0;i<n;i++) read(d[i]);
		vector<pair<int,int> > vec;
		for (int i=0;i<n;i++) if (d[i]!=1) vec.push_back(MP(d[i],i));
		sort(vec.begin(),vec.end());
		vector<int> v;
		for (pair<int,int> &A : vec) v.push_back(A.first);
		int flag=0; v1.clear(),v2.clear();
		if ((int)v.size()==2&&v[0]==2&&v[1]==2) {
			dy[vec[0].second]=0;
			dy[vec[1].second]=1;
			v1.push_back({0,1});
			v1.push_back({2,2});
			v1.push_back({1,0});
			v1.push_back({2,1});
			v1.push_back({0,2});
			v1.push_back({1,1});
			v1.push_back({2,0});
			v1.push_back({1,2});
		} else if ((int)v.size()==1&&v[0]==2) {
			dy[vec[0].second]=0;
			v1.push_back({1});
			v1.push_back({2});
		} else if ((int)v.size()==1&&v[0]==3) {
			dy[vec[0].second]=0;
			v1.push_back({2});
			v1.push_back({1});
			v1.push_back({3});
		} else if ((int)v.size()==0) {
			
		} else flag=1;
		if (flag) { puts("-1"); continue; }
		int sz=0;
		if ((int)v1.size()) sz=(int)v1.back().size();
		for (int i=0;i<n;i++) if (d[i]==1) {
			v2.clear(); dy[i]=sz;
			if ((int)v1.size()%2==0) {
				for (int j=0;j<v1.size();j++) {
					vector<int> A=v1[j];
					A.push_back(j%2==0?0:1);
					v2.push_back(A);
				}
				vector<int> A(sz,0);
				A.push_back(1);
				v2.push_back(A);
				for (int j=0;j<v1.size();j++) {
					vector<int> A=v1[j];
					A.push_back(j%2==0?1:0);
					v2.push_back(A);
				}
			} else if ((int)v1.size()==1) {
				vector<int> B=v1[0];
				B.push_back(0);
				v2.push_back(B);
				B.back()=1;
				v2.push_back(B);
				vector<int> A(sz,0);
				A.push_back(1);
				v2.push_back(A);
			} else {
				for (int j=0;j<v1.size();j++) {
					vector<int> A=v1[j];
					A.push_back(j%2==0?0:1);
					v2.push_back(A);
				}
				for (int j=(int)v1.size()-2;j>=0;j--) {
					vector<int> A=v1[j];
					A.push_back(j%2==0?1:0);
					v2.push_back(A);
				}
				vector<int> A(sz,0);
				A.push_back(1);
				v2.push_back(A);
				A=v1.back();
				A.push_back(1);
				v2.push_back(A);
			}
			v1.swap(v2); sz++;
		/*	for (vector<int> &A : v1) {
				for (int i=0;i<sz;i++) printf("%d ",A[i]); puts("");
			} puts("");*/
		}
		for (vector<int> &A : v1) {
			for (int i=0;i<n;i++) printf("%d ",A[dy[i]]); puts("");
		}
		for (int i=0;i+1<v1.size();i++) {
			assert(chk(v1[i],v1[i+1]));
		}
	}
	return 0;
}