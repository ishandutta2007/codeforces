#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int inf=0x3f3f3f3f;
const ll linf=0x3f3f3f3f3f3f3f3f;
const int maxn=1007;

int ans=0;
void f(int n)
{
    if(n<10){
        ans+=9;
        return;
    }
    ans+=(10-n%10);
    n/=10;
    n+=1;
    while(n%10==0)n/=10;
    f(n);
}

int main()
{
	int n;
	cin>>n;
	if(n%10==0){
        ans++;
        n++;
	}
	f(n);
	cout<<ans<<endl;
    return 0;
}