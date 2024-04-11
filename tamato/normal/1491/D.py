mod = 1000000007
eps = 10**-9


def main():
    import sys
    input = sys.stdin.buffer.readline

    for _ in range(int(input())):
        u, v = map(int, input().split())
        if u > v:
            print("NO")
            continue
        u_bin = bin(u)[2:]
        v_bin = bin(v)[2:]
        if u_bin.count("1") < v_bin.count("1"):
            print("NO")
            continue
        L = len(v_bin)
        u_bin = u_bin.zfill(L)
        ok = 1
        cnt_01 = cnt_10 = 0
        for i in range(L-1, -1, -1):
            if u_bin[i] == "0" and v_bin[i] == "1":
                cnt_01 += 1
            elif u_bin[i] == "1" and v_bin[i] == "0":
                cnt_10 += 1
            if cnt_01 > cnt_10:
                ok = 0
                break
        if ok:
            print("YES")
        else:
            print("NO")


if __name__ == '__main__':
    main()