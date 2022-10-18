def main():
    tt = int(input())
    for _ in range(tt):
        n = int(input())
        a = list(map(int, input().split()))
        a.sort()
        if n == 1:
            if a[0] == 1:
                print("YES")
            else:
                print("NO")
        elif a[-1] > a[-2] + 1:
            print("NO")
        else:
            print("YES")
main()