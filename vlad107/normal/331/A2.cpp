#include <stdio.h>
#include <algorithm>
#include <map>
#include <vector>

using namespace std;

int n,a[300500],l,r;
long long sa[300500],res=-1e18,cr;
vector<int>v;
map<int,int>s;

int main(){
    scanf("%d",&n);
    for (int i=0;i<n;i++){
        scanf("%d",&a[i]);
        sa[i]=(i?sa[i-1]:0)+(a[i]>0?a[i]:0);
        if (s.find(a[i])!=s.end()){
            cr=2*a[i]+sa[i-1]-sa[s[a[i]]];
            if (cr>res){
                res=cr;
                l=s[a[i]];
                r=i;
            }
        } else s[a[i]]=i;
    }
    for (int i=0;i<n;i++)
        if ((i<l)||(i>r)||((i>l)&&(i<r)&&(a[i]<0)))v.push_back(i+1);
    printf("%I64d %d\n",res,v.size());
    for (int i=0;i<v.size();i++)printf("%d ",v[i]);
}