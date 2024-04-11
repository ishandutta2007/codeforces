mod = 1000000007
eps = 10**-9


def main():
    import sys
    input = sys.stdin.buffer.readline

    N = int(input())
    AB = [-1] * (2*N+1)
    BA = [-1] * (2*N+1)
    for _ in range(N):
        a, b = map(int, input().split())
        AB[a] = b
        BA[b] = a
    seen = [0] * (2*N+1)
    small = 0
    large = 2*N+1
    top = []
    bottom = []
    ans = 0
    seen_sum = 0
    while True:
        cnt_all = 0
        cnt_flipped = 0
        small += 1
        cnt_all += 1
        if BA[small] != -1:
            cnt_flipped += 1
            L = BA[small]
        else:
            L = AB[small]
        top.append((small, L))
        seen[small] = 1
        seen[L] = 1
        small_new = small
        large_new = L

        seen_sum += 2
        while small != small_new or large_new != large:
            if large_new != large:
                for l in range(large - 1, large_new, -1):
                    if seen[l]:
                        continue
                    cnt_all += 1
                    if BA[l] != -1:
                        cnt_flipped += 1
                        s = BA[l]
                    else:
                        s = AB[l]
                    bottom.append((l, s))
                    seen[s] = 1
                    seen[l] = 1
                    seen_sum += 2
                    small_new = max(small_new, s)
                large = large_new
            elif small_new != small:
                for s in range(small + 1, small_new):
                    if seen[s]:
                        continue
                    cnt_all += 1
                    if BA[s] != -1:
                        cnt_flipped += 1
                        l = BA[s]
                    else:
                        l = AB[s]
                    top.append((s, l))
                    seen[s] = 1
                    seen[l] = 1
                    large_new = min(large_new, l)
                    seen_sum += 2
                small = small_new
            if seen_sum == 2*N:
                break
        ans += min(cnt_flipped, cnt_all - cnt_flipped)
        if seen_sum == 2*N:
            break

    bottom.reverse()
    top.extend(bottom)
    ok = 1
    for i in range(N-1):
        if top[i][0] > top[i+1][0] or top[i][1] < top[i+1][1]:
            ok = 0
            break
    if ok:
        print(ans)
    else:
        print(-1)


if __name__ == '__main__':
    main()