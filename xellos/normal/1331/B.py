N = int(input())
for i in range(2,N):
    if N%i == 0:
        print(str(i)+str(N//i))
        exit(0)