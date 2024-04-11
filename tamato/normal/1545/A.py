mod = 1000000007
eps = 10**-9


def main():
    import sys
    input = sys.stdin.buffer.readline

    for _ in range(int(input())):
        N = int(input())
        A = list(map(int, input().split()))

        IA = [(i, a) for i, a in enumerate(sorted(A))]
        cnt = {}
        for i, a in IA:
            if a in cnt:
                cnt[a][i&1] += 1
            else:
                cnt[a] = [0, 0]
                cnt[a][i&1] += 1
        cnt_ori = {}
        for i, a in enumerate(A):
            if a in cnt_ori:
                cnt_ori[a][i&1] += 1
            else:
                cnt_ori[a] = [0, 0]
                cnt_ori[a][i&1] += 1
        ok = 1
        for a in cnt:
            if cnt[a] != cnt_ori[a]:
                ok = 0
                break
        if ok:
            print("YES")
        else:
            print("NO")


if __name__ == '__main__':
    main()