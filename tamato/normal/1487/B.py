mod = 1000000007
eps = 10**-9


def main():
    import sys
    input = sys.stdin.buffer.readline

    for _ in range(int(input())):
        N, K = map(int, input().split())
        if K == 1:
            print(1)
            continue
        if not N & 1:
            print(((K-1)%N) + 1)
        else:
            loop_len = N // 2
            loop_num = K // loop_len
            rem = K % loop_len
            ans = (loop_len + 1) * loop_num
            if rem:
                ans += rem
            else:
                ans -= 1
            if ans % N == 0:
                print(N)
            else:
                print(ans % N)


if __name__ == '__main__':
    main()