def main():
    import sys
    input = sys.stdin.readline

    for _ in range(int(input())):
        N = int(input())
        m = int((N-1)**0.5)
        k = N - m**2
        if m <= 6:
            ans = [1] * N
            ans.append(3)
            ans.append(3)
            ans.append(7)
        else:
            a = m
            b = m - 6
            c = k
            d = 1
            while a + b + c + d + 4 > 10 ** 5:
                b += 1
                c -= m
            ans = [1] * a
            ans.append(3)
            ans.append(3)
            ans.extend([7] * b)
            ans.extend([1] * c)
            ans.append(3)
            ans.append(3)
            ans.append(7)
        print(''.join(map(str, ans)))


if __name__ == '__main__':
    main()