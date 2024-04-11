mod = 1000000007
eps = 10**-9


def main():
    import sys
    input = sys.stdin.buffer.readline

    for _ in range(int(input())):
        N, C = map(int, input().split())
        A = list(map(int, input().split()))
        A = list(set(A))
        A_set = set(A)

        ok = 1
        cs = [0] * (C + 1)
        for a in A:
            cs[a] += 1
        for i in range(1, C + 1):
            cs[i] += cs[i - 1]
        for a in A:
            for j in range(1, C + 1):
                if a * j > C:
                    break
                x = cs[min(C, a * (j + 1) - 1)] - cs[a * j - 1]
                if x:
                    if j not in A_set:
                        ok = 0
                        break
            if not ok:
                break
        if ok:
            print("Yes")
        else:
            print("No")


if __name__ == '__main__':
    main()