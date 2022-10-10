#include <iostream>
using namespace std;

using cat = long long;

inline cat get_min_sum_value(cat id, cat K) {
    return K*(K+1)/2 + id * (1+K*K) - (id%K);
}

inline cat get_max_sum_value(cat id, cat K) {
    return K*(K+1)/2 + id * (1+K*K) - (id%K) + K;
}

cat get_sum(cat id, cat K) {
    if(id%K == 0)
        return id*(1+K*K) + K*(K+1)/2;
    cat small_sum_id = id/K;
    cat min_summand = (id/K)*(1+K*K) + K + 1 + (id%K-1) * K;
    while(get_max_sum_value(small_sum_id, K) <= min_summand) {
        min_summand++;
        small_sum_id++;
    }
    if(get_min_sum_value(small_sum_id, K) >= min_summand+K)
        return K*(K-1)/2 + K*min_summand;
    if(cat small_sum = get_sum(small_sum_id, K); small_sum <= min_summand)
        return K*(K-1)/2 + K*min_summand + K;
    else if(small_sum <= min_summand+K-1)
        return K*(K-1)/2 + K*min_summand + K-(small_sum-min_summand);
    else
        return K*(K-1)/2 + K*min_summand;
}

pair<cat, cat> get_first_ge_sum(cat N, cat K) {
    if(N < K*(K+1)/2)
        return {0, K*(K+1)/2};
    cat dif = K * (1 + K*K); // sum(K*i+K) - sum(K*i)
    cat cur_id = (N - K*(K+1)/2) / dif * K;
    if(get_min_sum_value(cur_id, K) >= N)
        return {cur_id+1, get_min_sum_value(cur_id, K)};
    cat max_dif = K + K*K; // max sum(i+1)-sum(i)
    cur_id += min(K-1, (N - get_min_sum_value(cur_id, K) + max_dif-1) / max_dif);
    if(cat cur_sum = get_sum(cur_id, K); cur_sum < N)
        return {cur_id+2, cur_sum};
    else
        return {cur_id+1, cur_sum};
}

cat solve(cat N, cat K) {
    if(N < K*(K+1)/2)
        return N+(N-1)/K;
    auto [id, sum] = get_first_ge_sum(N, K);
    if(id == -1)
        return -1;
    if(sum == N)
        return id * (K+1);
    else
        return (N-id)/K + N-id+1;
}

int main() {
    cin.sync_with_stdio(0);
    cin.tie(0);
    int T;
    cin >> T;
    while(T--) {
        cat N, K;
        cin >> N >> K;
        cat ans = solve(N, K);
        if(ans == -1)
            return 1;
        cout << ans << "\n";
    }
}