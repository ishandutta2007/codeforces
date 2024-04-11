mod = 1000000007
eps = 10**-9


def main():
    import sys
    input = sys.stdin.readline

    N = int(input())
    S = input().rstrip('\n')

    a_num = [0] * (N+1)
    q_num_left = [0] * (N+1)
    for i, s in enumerate(S):
        a_num[i+1] = a_num[i]
        q_num_left[i+1] = q_num_left[i]
        if s == "a":
            a_num[i+1] += 1
        if s == "?":
            q_num_left[i+1] += 1
    S_rev = S[::-1]
    c_num = [0] * (N+1)
    q_num_right = [0] * (N+1)
    for i, s in enumerate(S_rev):
        c_num[i+1] = c_num[i]
        q_num_right[i+1] = q_num_right[i]
        if s == "c":
            c_num[i+1] += 1
        if s == "?":
            q_num_right[i+1] += 1

    ans = 0
    k = q_num_left[-1]
    k0 = pow(3, k, mod)
    k1 = pow(3, max(0, k-1), mod)
    k2 = pow(3, max(0, k-2), mod)
    k3 = pow(3, max(0, k-3), mod)
    for i, s in enumerate(S):
        if s == "b":
            # ac
            ans = (ans + ((a_num[i] * c_num[N - i - 1])%mod * k0)%mod)%mod
            # ?c
            ans = (ans + ((q_num_left[i] * c_num[N - i - 1])%mod * k1)%mod)%mod
            # a?
            ans = (ans + ((a_num[i] * q_num_right[N - i - 1])%mod * k1)%mod)%mod
            # ??
            ans = (ans + ((q_num_left[i] * q_num_right[N - i - 1]) % mod * k2) % mod) % mod
        elif s == "?":
            # ac
            ans = (ans + ((a_num[i] * c_num[N - i - 1]) % mod * k1) % mod) % mod
            # ?c
            ans = (ans + ((q_num_left[i] * c_num[N - i - 1]) % mod * k2) % mod) % mod
            # a?
            ans = (ans + ((a_num[i] * q_num_right[N - i - 1]) % mod * k2) % mod) % mod
            # ??
            ans = (ans + ((q_num_left[i] * q_num_right[N - i - 1]) % mod * k3) % mod) % mod
    print(ans)


if __name__ == '__main__':
    main()