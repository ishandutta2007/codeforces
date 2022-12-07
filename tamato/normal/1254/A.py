mod = 1000000007
eps = 10**-9


def main():
    import sys
    from string import ascii_letters, digits
    input = sys.stdin.readline

    SS = ascii_letters + digits
    for _ in range(int(input())):
        H, W, K = map(int, input().split())

        S = SS[:K]
        grid = []
        for _ in range(H):
            grid.append(input().rstrip('\n'))

        num_rice = 0
        for h in range(H):
            for w in range(W):
                if grid[h][w] == "R":
                    num_rice += 1

        minor = num_rice // K
        major = minor + 1
        num_major = num_rice % K
        i = 0
        cnt = 0
        ans = [[""] * W for _ in range(H)]
        for h in range(H):
            if h&1:
                for w in range(W-1, -1, -1):
                    if grid[h][w] == "R":
                        cnt += 1
                        ans[h][w] = S[i]
                        if i < num_major:
                            if cnt == major:
                                cnt = 0
                                if i != K-1:
                                    i += 1
                        else:
                            if cnt == minor:
                                cnt = 0
                                if i != K-1:
                                    i += 1
                    else:
                        ans[h][w] = S[i]
            else:
                for w in range(W):
                    if grid[h][w] == "R":
                        cnt += 1
                        ans[h][w] = S[i]
                        if i < num_major:
                            if cnt == major:
                                cnt = 0
                                if i != K - 1:
                                    i += 1
                        else:
                            if cnt == minor:
                                cnt = 0
                                if i != K - 1:
                                    i += 1
                    else:
                        ans[h][w] = S[i]

        for h in range(H):
            print("".join(ans[h]))


if __name__ == '__main__':
    main()