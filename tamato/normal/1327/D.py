def main():
    import sys
    input = sys.stdin.buffer.readline

    div = [[] for _ in range(2*10**5+1)]
    for d in range(1, 2*10**5+1):
        for i in range(1, 2*10**5+1):
            if d*i > 2*10**5:
                break
            div[d*i].append(d)

    for t in range(int(input())):
        N = int(input())
        P = list(map(int, input().split()))
        C = list(map(int, input().split()))

        seen = [0] * (N+1)
        ans = N
        for i in range(1, N+1):
            if not seen[i]:
                seen[i] = 1
                cycle = [i]
                x = i
                while True:
                    x = P[x-1]
                    if x == i:
                        break
                    cycle.append(x)
                    seen[x] = 1
                L = len(cycle)
                fin = 0
                for d in div[L]:
                    for mod in range(d):
                        flg = 2
                        for i in range(mod, L, d):
                            if flg == 2:
                                color = C[cycle[i]-1]
                                flg = 1
                            else:
                                if C[cycle[i]-1] != color:
                                    flg = 0
                                    break
                        if flg:
                            ans = min(ans, d)
                            #print(t, cycle, d, mod)
                            fin = 1
                            break
                    if fin:
                        break
        print(ans)


if __name__ == '__main__':
    main()