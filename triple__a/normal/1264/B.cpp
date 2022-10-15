#include<bits/stdc++.h>
using namespace std;
 
int a,b,c,d;
int main(){
    cin>>a>>b>>c>>d;
    int u=a+c,v=b+d;
    if (max(u,v)>min(u,v)+1){
        cout<<"NO";
        return 0;
    }
    if (a>b){
        if (c==0&&d==0){
            cout<<"YES"<<endl;
            for (int i=0;i<b;++i) cout<<"0 1 ";
            cout<<0;
            return 0;
        }
        cout<<"NO";
        return 0;
    }
    if (d>c){
        if (a==0&&b==0){
            cout<<"YES"<<endl;
            for (int i=0;i<c;++i) cout<<"3 2 ";
            cout<<3;
            return 0;
            
        }
        cout<<"NO";
        return 0;
    }
    cout<<"YES"<<endl;
    if (u>v){
        for (int i=0;i<a;++i){
            cout<<"0 1 ";
        }
        for (int i=0;i<d;++i){
            cout<<"2 3 ";
        }
        for (int i=0;i<b-a;++i){
            cout<<"2 1 ";
        }
        cout<<"2";
    }
    else{
        for (int i=0;i<d;++i){
            cout<<"3 2 ";
        }
        for (int i=0;i<a;++i){
            cout<<"1 0 ";
        }
        for (int i=0;i<c-d;++i){
            cout<<"1 2 ";
        }
        if (v>u) cout<<1;
    }
    return 0;
}