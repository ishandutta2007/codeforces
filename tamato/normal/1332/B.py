def main():
    import sys
    input = sys.stdin.buffer.readline

    P = [2, 3, 5, 7, 11, 13, 17, 19, 23, 29, 31]

    for _ in range(int(input())):
        N = int(input())
        A = list(map(int, input().split()))

        ans = [0] * N
        seen = {}
        k = 1
        for i, a in enumerate(A):
            for j, p in enumerate(P):
                if a % p == 0:
                    if not p in seen:
                        seen[p] = k
                        ans[i] = k
                        k += 1
                    else:
                        ans[i] = seen[p]
                    break
        print(max(ans))
        print(*ans)


if __name__ == '__main__':
    main()