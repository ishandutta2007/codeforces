def main():
    import sys
    input = sys.stdin.readline

    t = int(input())
    for _ in range(t):
        N = input().rstrip('\n')
        odd = []
        even = []
        for n_ in N:
            n = int(n_)
            if n % 2:
                odd.append(n)
            else:
                even.append(n)
        odd.reverse()
        even.reverse()
        ans = []
        while True:
            if len(odd) == 0:
                even.reverse()
                ans.extend(even)
                break
            elif len(even) == 0:
                odd.reverse()
                ans.extend(odd)
                break
            else:
                if odd[-1] < even[-1]:
                    ans.append(odd.pop())
                else:
                    ans.append(even.pop())
        print(''.join(map(str, ans)))


if __name__ == '__main__':
    main()