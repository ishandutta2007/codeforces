def main():
    import sys
    input = sys.stdin.buffer.readline

    N, M = map(int, input().split())
    S = input().split()
    S = S[0].decode()

    B1 = [[0] * (N+1) for _ in range(26)]
    #B2 = [[0] * (N+1) for _ in range(26)]
    mod1 = 1000000007
    #mod2 = 1000000009
    base1 = 2
    #base2 = 2009
    base1_inv_list = [1] * N
    #base2_inv_list = [1] * N
    base1_inv = pow(base1, mod1-2, mod1)
    #base2_inv = pow(base2, mod2-2, mod2)
    for i in range(1, N):
        base1_inv_list[i] = (base1_inv_list[i-1] * base1_inv)%mod1
        #base2_inv_list[i] = (base2_inv_list[i-1] * base2_inv)%mod2

    p1 = p2 = 1
    for i, s in enumerate(S):
        j = ord(s) - 97
        p1 = (p1 * base1)%mod1
        #p2 = (p2*base2)%mod2
        B1[j][i+1] = p1
        #B2[j][i+1] = p2
    for j_ in range(26):
        for i in range(N):
            new = B1[j_][i+1] + B1[j_][i]
            if new >= mod1:
                new -= mod1
            B1[j_][i+1] = new
            #B2[j_][i + 1] = (B2[j_][i + 1] + B2[j_][i]) % mod2
    ans = [''] * M

    for m in range(M):
        x, y, L = map(int, input().split())
        #X1 = []
        #X2 = [0] * 26
        #Y1 = []
        #Y2 = [0] * 26
        seen1 = {}
        for j in range(26):
            x1 = (((B1[j][x + L - 1] - B1[j][x - 1]) % mod1) * base1_inv_list[x - 1]) % mod1
            # X2[j] = (((B2[j][x + L-1] - B2[j][x - 1]) % mod2) * base2_inv_list[x-1])%mod2
            y1 = (((B1[j][y + L - 1] - B1[j][y - 1]) % mod1) * base1_inv_list[y - 1]) % mod1
            # Y2[j] = (((B2[j][y + L-1] - B2[j][y - 1]) % mod2) * base2_inv_list[y-1])%mod2
            if x1 not in seen1:
                seen1[x1] = 1
            else:
                seen1[x1] += 1
            if y1 not in seen1:
                seen1[y1] = 1
            else:
                seen1[y1] += 1
        #X1.sort()
        #X2.sort()
        #Y1.sort()
        #Y2.sort()
        ok = 1
        #for j in range(26):
            #if heappop(X1) != heappop(Y1):
            #    ok = 0
            #    break
            #if X2[j] != Y2[j]:
            #   ok = 0
            #    break
        for z in seen1.values():
            if z&1:
                ok = 0
                break
        if ok:
            ans[m] = 'YES'
        else:
            ans[m] = 'NO'
    print('\n'.join(ans))


if __name__ == '__main__':
    main()