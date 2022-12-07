def main():
    import sys
    input = sys.stdin.readline

    for _ in range(int(input())):
        S = input().rstrip('\n')
        N = len(S)

        cnt = 0
        ans = 0
        for i, s in enumerate(S):
            if s == '0':
                cnt += 1
            else:
                j = 0
                f = 0
                while True:
                    f *= 2
                    f += int(S[i+j])
                    if f - (j+1) <= cnt:
                        ans += 1
                        #print(i, f, j)
                    else:
                        break
                    j += 1
                    if i+j == N:
                        break
                cnt = 0
        print(ans)


if __name__ == '__main__':
    main()