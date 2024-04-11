#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int inf=0x3f3f3f3f;
const ll linf=0x3f3f3f3f3f3f3f3f;
const int maxn=2e5+10;

int main()
{
	int n,a[maxn],b[10];
	cin>>n;

	for(int i=0;i<n;i++){
        scanf("%1d",&a[i]);
	}
	for(int i=1;i<=9;i++)scanf("%d",&b[i]);
	bool flag=0,used=0;
	for(int i=0;i<n;i++){
        if(used){
            cout<<a[i];
        }
        else{
            if(flag)
            {
                if(a[i]<=b[a[i]]){
                    cout<<b[a[i]];
                }
                else{
                    cout<<a[i];
                    used=1;
                }
            }
            else{
                if(a[i]<b[a[i]]){
                    cout<<b[a[i]];
                    flag=1;
                }
                else{
                    cout<<a[i];
                }
            }
        }
	}
    return 0;
}