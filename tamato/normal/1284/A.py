def main():
    import sys
    input = sys.stdin.readline

    N, M = map(int, input().split())
    S = list(input().split())
    T = list(input().split())
    Q = int(input())
    for _ in range(Q):
        y = int(input())
        y -= 1
        print(S[y%N] + T[y%M])


if __name__ == '__main__':
    main()