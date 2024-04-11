#include <bits/stdc++.h>
typedef long long ll;

using namespace std;

int main(){
    int n;
    scanf("%d",&n);
    map<int,int> m;
    for (int i=0;i<n;i++)
    {
        int a;
        scanf("%d",&a);
        if (m.find(a)==m.end()) m[a]=0;
        m[a]++;
    }
    
    if (m.size()==2) 
    {
        auto it=m.begin();
        int a=it->first;
        it++;
        int b=it->first;
        if (b-a==2) m[(a+b)/2]=0;
    }
    if (m.size()<3){
        printf("%d\n",n);
        for (auto i:m)
        {
            for (int j=0;j<i.second;j++) {printf("%d ",i.first);}
            }
    }
    else {
            int max1=0;
            int max2=0;
            auto itt=m.begin();
            int n1=(itt++)->second;
            int n2=(itt++)->second;
            int n3=(itt)->second;
            max1=n2/2;
            max2=min(n1,n3);
            auto it=m.begin();
            if (max1>=max2){
                    printf("%d\n",n-max1*2);
                    for (int i=0;i<max1+n1;i++) {printf("%d\n",it->first);}
                    it++;
                    if (n2%2) printf("%d ",it->first);
                    it++;
                    for (int i=0;i<max1+n3;i++) {printf("%d\n",it->first);}
                }
            else{
                    printf("%d\n",n-max2*2);
                    for (int i=0;i<n1-max2;i++) {printf("%d\n",it->first);}
                    it++;
                    for (int i=0;i<n2+max2*2;i++) printf("%d ",it->first);
                    it++;
                    for (int i=0;i<n3-max2;i++) {printf("%d\n",it->first);}
            }
            
        }
}