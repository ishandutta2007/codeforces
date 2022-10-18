#include<bits/stdc++.h>
#define pb push_back
#define mp make_pair
using namespace std;

const int N = 101;
vector <int> a;
int p[N];

int main(){
    int n, k, x[N], sum = 0, answer = 0;
    cin >> n >> k;
    for (int i = 1; i <= n; i++){
    	cin >> x[i];
    }
    for (int i = 1; i <= n; i++){
    	p[i] = p[i - 1];
        if (x[i] % 2 == 1){
        	p[i]++;
        }
        else{
        	p[i]--;
        }
    }
    for (int i = 1; i < n; i++){
        if (!p[i]){
        	a.push_back(abs(x[i + 1] - x[i]));
        }
    }
    sort(a.begin(), a.end());
    for (int y : a){
        if (sum + y > k){
        	break;
        }
        sum += y;
        answer++;
    }   
    cout << answer;
}