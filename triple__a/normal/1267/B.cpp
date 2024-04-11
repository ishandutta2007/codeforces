#include<bits/stdc++.h>
using namespace std;

string s;
int n;
vector<pair<char,int> >vec;
int main(){
    cin>>s;
    n=s.size();
    int i,j=0;
    while (i<n){
        int j=i;
        while (i+1<n&&s[i]==s[i+1]) i++;
        vec.push_back({s[i],i-j+1});
        i++;
    }
    if (vec.size()%2==0){puts("0"); return 0;}
    for (int i=0;i<vec.size();++i){
        if (vec[vec.size()-i-1].first!=vec[i].first||vec[vec.size()-i-1].second+vec[i].second<=2){
            puts("0");
            return 0;
        }
    }
    if (vec[vec.size()/2].second>=2){
    printf("%d\n",vec[vec.size()/2].second+1);
    }
    else{
        printf("0");
    }
    return 0;
}