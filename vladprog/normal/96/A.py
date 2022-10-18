from math import*

def main():
    R=lambda:map(int,input().split())
    s=input()
    if ('1111111' in s) or ('0000000' in s):
        print('YES')
    else:
        print('NO')

main()