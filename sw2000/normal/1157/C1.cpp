#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int inf=0x3f3f3f3f;
const ll linf=0x3f3f3f3f3f3f3f3f;
const int maxn=2e5+10;

int main()
{
	int a[maxn],st=1,en,n,now=0;
	string ans;
	cin>>n;
	en=n;
	for(int i=1;i<=en;i++)scanf("%d",&a[i]);

	while(1)
    {
        if(st>en||a[st]<now&&a[en]<now)break;
        else{
            if(a[st]>now&&a[en]>now){
                if(a[st]<a[en]){
                    ans.push_back('L');
                    now=a[st];
                    st++;
                }
                else{
                    ans.push_back('R');
                    now=a[en];
                    en--;
                }
            }
            else{
                if(a[st]>now){
                    ans.push_back('L');
                    now=a[st];
                    st++;
                }
                else{
                    ans.push_back('R');
                    now=a[en];
                    en--;
                }
            }
        }
    }
    cout<<ans.length()<<endl<<ans;
    return 0;
}