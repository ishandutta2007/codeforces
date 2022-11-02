#include<cstdio>
#include<vector>
#include<algorithm>

using namespace std;

struct seg{
    int l, r;
    void get(){scanf("%d%d", &l, &r);}
};

bool cmp(const seg & a, const seg & b){
    return a.r < b.r;
}

int cnt = 1;
int n;
vector<seg> a;

int main(){
    scanf("%d", &n);
    a.resize(n);
    for(int i = 0; i < n; i++){a[i].get();}
    sort(a.begin(), a.end(), cmp);
    cnt = 1; int j = 0;
    for(int i = 1; i < n; i++){
        if(a[i].l > a[j].r){cnt++; j = i;}
    }
    printf("%d", cnt);
    return 0;
}