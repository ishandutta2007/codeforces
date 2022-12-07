mod = 1000000007
eps = 10**-9


def main():
    import sys
    input = sys.stdin.readline

    H, W = map(int, input().split())
    G = []
    for _ in range(H):
        G.append(list(map(int, input().split())))

    C = {}
    for h in range(H):
        for w in range(W):
            c = G[h][w]
            if c not in C:
                C[c] = []
            C[c].append((h, w))

    ans = 0
    for c in C:
        cnt_H = {}
        cnt_W = {}
        for h, w in C[c]:
            if h not in cnt_H:
                cnt_H[h] = 0
            if w not in cnt_W:
                cnt_W[w] = 0
            cnt_H[h] += 1
            cnt_W[w] += 1
        H_list = sorted(list(cnt_H.keys()))
        W_list = sorted(list(cnt_W.keys()))

        cnt = 0
        S = 0
        for h in H_list:
            n = cnt_H[h]
            ans += n * (cnt * h - S)
            cnt += n
            S += n * h
        cnt = 0
        S = 0
        for w in W_list:
            n = cnt_W[w]
            ans += n * (cnt * w - S)
            cnt += n
            S += n * w
    print(ans)


if __name__ == '__main__':
    main()