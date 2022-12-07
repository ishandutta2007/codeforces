def main():
    import sys
    input = sys.stdin.readline

    for _ in range(int(input())):
        line = list(input().split())
        N = int(line[0])
        S = line[1]

        inc_num = S.count('<')
        ans = [0] * N
        inc = N
        dec = N - inc_num
        for i in range(N - 1):
            if ans[i+1]:
                continue
            if S[i] == '<':
                j = i+1
                cnt = 1
                while True:
                    if j == N-1:
                        break
                    if S[j] == '<':
                       cnt += 1
                    else:
                        break
                    j += 1
                #print(cnt)
                for j in range(i+cnt-1, i-1, -1):
                    #print(j)
                    ans[j+1] = inc
                    inc -= 1
        for i in range(N):
            if ans[i] == 0:
                ans[i] = dec
                dec -= 1
        print(*ans)

        ans = [0] * N
        inc = N - inc_num + 1
        dec = N - inc_num
        for i in range(N - 1):
            if S[i] == '<':
                ans[i + 1] = inc
                inc += 1
        for i in range(N):
            if ans[i] == 0:
                ans[i] = dec
                dec -= 1
        print(*ans)


if __name__ == '__main__':
    main()