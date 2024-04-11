mod = 1000000007
eps = 10**-9


def main():
    import sys
    input = sys.stdin.buffer.readline

    for _ in range(int(input())):
        H, W, a, b = map(int, input().split())
        if H * a != W * b:
            print("NO")
            continue
        print("YES")
        ans = [[0] * W for _ in range(H)]
        for h in range(H):
            for w in range(W):
                if (h*a+w) % W < a:
                    ans[h][w] = 1
        for h in range(H):
            print("".join(map(str, ans[h])))


if __name__ == '__main__':
    main()