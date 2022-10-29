#include <iostream>
using namespace std;
int A[200005];
int main(int argc, char** argv) {
	int T;
	cin >> T;
	while(T--)
	{
		int n;
		cin >> n;
		for(int i=1;i<=n;i++)
			cin >> A[i];
		int l=1,r=n,now=0;
		int cnt=0,a=0,b=0;
		while(l<=r)
		{
			int s=0;
			for(int i=l;i<=r;i++)
			{
				s+=A[l];
				++l;
				if(s>now) break;
			}
			if(s) now=max(now,s),a+=s,++cnt;
			s=0;
			for(int i=r;i>=l;i--)
			{
				s+=A[r];
				--r;
				if(s>now) break;
			}
			if(s) now=s,b+=s,++cnt;
		}
		cout << cnt << " " << a << " " << b << "\n"; 
	}
	return 0;
}