mod = 1000000007
eps = 10**-9


def main():
    import sys
    input = sys.stdin.readline

    for _ in range(int(input())):
        N = int(input())
        S = input().rstrip('\n')
        S = [int(s) for s in S[::-1]]

        A = []
        prev = S[0]
        cnt = 0
        for s in S:
            if s == prev:
                cnt += 1
            else:
                A.append(cnt)
                cnt = 1
                prev ^= 1
        A.append(cnt)

        ans = 0
        i = len(A) - 1
        while A:
            ans += 1
            # step 1
            if i >= 0:
                while True:
                    if A[i] > 1:
                        A[i] -= 1
                        break
                    else:
                        i -= 1
                        if i < 0:
                            A.pop()
                            break
            else:
                A.pop()

            # step 2
            if A:
                A.pop()
                if i == len(A):
                    i -= 1
        print(ans)


if __name__ == '__main__':
    main()