n=int(input())
for i in range(n):
    print(2**(bin(int(input())).count("1")))