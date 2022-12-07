mod = 1000000007
eps = 10**-9


def main():
    import sys
    input = sys.stdin.readline

    N = int(input())
    A_list = [list(map(int, input().split()))]

    cnt = 0
    x = 0
    for lv in range(30, -1, -1):
        A_list_new = []
        inv_sum = 0
        inv_max = 0
        for A in A_list:
            AA = [a >> lv & 1 for a in A]
            zero = 0
            one = 0
            inv = 0
            A_new_0 = []
            A_new_1 = []
            for i, a in enumerate(AA):
                if a == 0:
                    zero += 1
                    inv += one
                    A_new_0.append(A[i])
                else:
                    one += 1
                    A_new_1.append(A[i])
            if A_new_0:
                A_list_new.append(A_new_0)
            if A_new_1:
                A_list_new.append(A_new_1)
            inv_max += zero * one
            inv_sum += inv
        inv_flipped = inv_max - inv_sum
        if inv_sum <= inv_flipped:
            cnt += inv_sum
        else:
            cnt += inv_flipped
            x += 1 << lv
        A_list = A_list_new
    print(cnt, x)


if __name__ == '__main__':
    main()