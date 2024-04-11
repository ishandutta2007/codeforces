def main():
    import sys
    input = sys.stdin.readline

    t = int(input())
    for _ in range(t):
        N = int(input())
        odd = 0
        zero_num = 0
        for _ in range(N):
            s = input().rstrip('\n')
            L = len(s)
            if L % 2 == 1:
                odd = 1
            zero_num += s.count('0')
        if odd:
            print(N)
        else:
            if zero_num % 2 == 1:
                print(N-1)
            else:
                print(N)


if __name__ == '__main__':
    main()