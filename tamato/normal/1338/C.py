mod = 1000000007
eps = 10**-9


def main():
    import sys
    input = sys.stdin.buffer.readline

    for _ in range(int(input())):
        N = int(input())
        if N <= 3:
            print(N)
            continue
        if N%3 == 1:
            k = N.bit_length()-1
            if k&1:
                k -= 1
            print(2**k + (N-2**k) // 3)
        elif N%3 == 2:
            N1 = N-1
            k = N1.bit_length()-1
            if k&1:
                k -= 1
            ans1 = 2**k + (N1-2**k) // 3
            ans = 0
            cnt = 0
            while ans1:
                a = ans1 % 4
                if a == 1:
                    a = 2
                elif a == 2:
                    a = 3
                elif a == 3:
                    a = 1
                ans += a * (4**cnt)
                cnt += 1
                ans1 >>= 2
            print(ans)
        else:
            N1 = N - 2
            k = N1.bit_length()-1
            if k & 1:
                k -= 1
            ans1 = 2 ** k + (N1 - 2 ** k) // 3
            ans = 0
            cnt = 0
            while ans1:
                a = ans1 % 4
                if a == 1:
                    a = 3
                elif a == 2:
                    a = 1
                elif a == 3:
                    a = 2
                ans += a * (4 ** cnt)
                cnt += 1
                ans1 >>= 2
            print(ans)


if __name__ == '__main__':
    main()