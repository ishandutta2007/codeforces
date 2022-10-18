#include<bits/stdc++.h>
using namespace std;

typedef pair<int, int> i;
vector<int> posl[27], posr[27];
int n, cnt1, cnt2;
string l, r;
vector<i> a;

int main(){
    cin >> n >> l >> r;
    l = '0' + l;
    r = '0' + r;
    for(int i = 1; i <= n; i++){
        if(l[i] != '?') posl[l[i] - 'a'].push_back(i);
        else posl[26].push_back(i);
        if(r[i] != '?') posr[r[i] - 'a'].push_back(i);
        else posr[26].push_back(i);
    }
    for(int i = 0; i < 26; i++){
        for(int j = 0; j < min(posl[i].size(), posr[i].size()); j++){
            a.push_back(make_pair(posl[i][j], posr[i][j]));
        }
        if(posl[i].size() < posr[i].size()){
            for(int j = posl[i].size(); j < posr[i].size() && cnt1 < posl[26].size(); j++){
                a.push_back(make_pair(posl[26][cnt1], posr[i][j]));
                cnt1++;
            }
        }
        else{
            for(int j = posr[i].size(); j < posl[i].size() && cnt2 < posr[26].size(); j++){
                a.push_back(make_pair(posl[i][j], posr[26][cnt2]));
                cnt2++;
            }
        }
    }
    //cout << a.size() << endl;
    //cout << cnt1 << " " << cnt2 << endl;
    //cout << posl[26].size()<< " " << posr[26].size() << endl;
    int tmp1 = posl[26].size() - cnt1, tmp2 = posr[26].size() - cnt2;
    for(int i = 0; i < min(tmp1, tmp2); i++){
        a.push_back(make_pair(posl[26][cnt1], posr[26][cnt2]));
        cnt1++;
        cnt2++;
    }
    cout << a.size() << endl;
    for(int i = 0; i < a.size(); i++){
        cout << a[i].first << " " << a[i].second << endl;
    }
}