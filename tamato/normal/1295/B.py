def main():
    import sys
    input = sys.stdin.readline

    for _ in range(int(input())):
        N, X = map(int, input().split())
        S = input().rstrip('\n')

        B = [0] * N
        for i, s in enumerate(S):
            if s == '0':
                B[i] = B[i-1] + 1
            else:
                B[i] = B[i-1] - 1
        if B[-1] == 0:
            if X == 0:
                print(-1)
                continue
            else:
                if X in B:
                    print(-1)
                    continue
                else:
                    print(0)
                    continue
        ans = 0
        Blast = B[-1]
        for b in B:
            if (X - b) % Blast == 0 and (X - b) * Blast >= 0:
                ans += 1
        if X == 0:
            ans += 1
        print(ans)


if __name__ == '__main__':
    main()