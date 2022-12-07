def main():
    import sys
    input = sys.stdin.readline

    N, H = map(int, input().split())

    if (H * (H+1)) // 2 >= N:
        ok = H
        ng = 0
        mid = (ok+ng) // 2
        while ok - ng > 1:
            if ((mid+1) * mid) // 2 >= N:
                ok = mid
            else:
                ng = mid
            mid = (ok+ng)//2
        print(ok)
        exit()

    ok = 10**12
    ng = 0
    mid = (ok+ng)//2
    while ok - ng > 1:
        if (mid + H) & 1:
            x = (H+mid-1) // 2
            M = (x * (x+1)) // 2 + ((x + H) * (x-H+1))//2
        else:
            x = (H + mid) // 2
            M = (x * (x + 1)) // 2 + ((x-1 + H) * (x - H)) // 2
        if M >= N:
            ok = mid
        else:
            ng = mid
        mid = (ok+ng)//2
        #print(ok, ng, mid, M)
    print(ok)


if __name__ == '__main__':
    main()