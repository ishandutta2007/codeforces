def main():
    tt = int(input())
    for _ in range(tt):
        a, b = map(int,input().split())
        if a == 0:
            print(1)
        else:
            print(a + b + b + 1)
main()