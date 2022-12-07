mod = 998244353
eps = 10**-9


def main():
    import sys
    input = sys.stdin.readline

    N, M = map(int, input().split())
    A = list(map(int, input().split()))
    B = list(map(int, input().split()))

    A_unique = sorted(list(set(A)))
    A_set = set(A)
    B_set = set(B)
    if A_unique[0] not in B_set:
        print(0)
        exit()
    for b in B:
        if b not in A_set:
            print(0)
            exit()
    B_set.remove(A_unique[0])
    pos = {}
    for i, a in enumerate(A):
        pos[a] = i
    ans = 1
    r = -1
    for a in A_unique:
        if a in B_set:
            i = pos[a]
            if i < r:
                print(0)
                exit()
            ans = (ans * (i-r))%mod
        r = max(r, pos[a])
    print(ans)


if __name__ == '__main__':
    main()