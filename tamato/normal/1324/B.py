def main():
    import sys
    input = sys.stdin.readline

    for _ in range(int(input())):
        N = int(input())
        A = list(map(int, input().split()))
        dic = {}
        ok = 0
        for i, a in enumerate(A):
            if a not in dic:
                dic[a] = i
            else:
                if i - dic[a] > 1:
                    ok = 1
                    break
        if ok:
            print('YES')
        else:
            print('NO')


if __name__ == '__main__':
    main()