mod = 1000000007
eps = 10**-9


def main():
    import sys
    from random import sample
    from bisect import bisect_left
    input = sys.stdin.readline

    N = int(input())
    A = list(map(int, input().split()))
    rmax = 1 << 30

    left_bound = [0] * N
    l = N-1
    cnt = [0] * (N+1)
    cnt[A[-1]] += 1
    for r in range(N-1, -1, -1):
        if r+1 < N:
            cnt[A[r+1]] -= 1
        while l:
            al = A[l-1]
            if cnt[al] < 3:
                l -= 1
                cnt[al] += 1
            else:
                break
        left_bound[r] = l

    cnt_min = [N+1] * (N+1)
    loop_num = 2
    for _ in range(loop_num):
        r0r1_lower = sample(range(rmax), k=(N+1)*2)
        r0r1_upper = sample(range(rmax), k=(N+1)*2)
        r0r1 = [(r0r1_upper[i] << 30) + r0r1_lower[i] for i in range((N+1)*2)]
        r0 = r0r1[:N+1]
        r1 = r0r1[N+1:]
        r2 = [r0[i] ^ r1[i] for i in range(N+1)]
        cs = [0] * (N+1)
        flg = [0] * (N+1)
        dic = {0: [-1]}
        for i, a in enumerate(A):
            if flg[a] == 0:
                r = r0[a]
            elif flg[a] == 1:
                r = r1[a]
            else:
                r = r2[a]
            flg[a] = (flg[a] + 1) % 3
            h = cs[i] ^ r
            if h in dic:
                j = bisect_left(dic[h], left_bound[i] - 1)
                cnt_min[i+1] = min(cnt_min[i+1], len(dic[h]) - j)
                dic[h].append(i)
            else:
                dic[h] = [i]
            cs[i + 1] = h
    ans = 0
    for i in range(1, N+1):
        if cnt_min[i] != N+1:
            ans += cnt_min[i]
    print(ans)


if __name__ == '__main__':
    main()