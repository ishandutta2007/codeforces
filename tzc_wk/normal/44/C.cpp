#include<bits/stdc++.h>
using namespace std;
int aa[105],bb[105],a[101],m,n;
int main(){
        cin>>m>>n;
        for (int i=0;i<n;i++) cin>>aa[i]>>bb[i];  
         for(int i=0;i<n;i++)
            for(int j=aa[i];j<=bb[i];j++)
                a[j]++;
        for(int j=1;j<=m;j++)
            if(a[j]==0||a[j]>1) 
            {cout<<j<<" "<<a[j]<<endl;
            return 0;
            }
        cout<<"OK";
}