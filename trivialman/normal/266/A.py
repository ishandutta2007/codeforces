n=int(input())
str0=input()
print(len(str0)-(1+len([1 for i in range(1,len(str0)) if str0[i]!=str0[i-1]])))