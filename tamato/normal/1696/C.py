mod = 998244353


def main():
    import sys
    input = sys.stdin.buffer.readline

    for _ in range(int(input())):
        N, M = map(int, input().split())
        A = list(map(int, input().split()))
        K = int(input())
        B = list(map(int, input().split()))

        if sum(A) != sum(B):
            print("NO")
            continue

        M_pow = {}
        m = 1
        p = 0
        while m <= 10 ** 9:
            M_pow[m] = p
            m *= M
            p += 1

        AA = []
        for a in A:
            cnt = 0
            aa = a
            while True:
                if aa % M == 0:
                    cnt += 1
                    aa //= M
                else:
                    break
            if AA:
                if AA[-1][0] == aa:
                    AA[-1][1] += M ** cnt
                else:
                    AA.append([aa, M ** cnt])
            else:
                AA.append([aa, M ** cnt])
        AA.reverse()
        ok = 1
        for b in B:
            if not AA:
                ok = 0
                break
            a = AA[-1][0]
            if b % a != 0:
                ok = 0
                break
            x = b // a
            if x not in M_pow:
                ok = 0
                break
            if AA[-1][1] < x:
                ok = 0
                break
            else:
                AA[-1][1] -= x
                if AA[-1][1] == 0:
                    AA.pop()
        if ok:
            print("YES")
        else:
            print("NO")


if __name__ == '__main__':
    main()