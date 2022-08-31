c=input()
a=int(c,2)
b=int(input(),2)
x=bin(a^b)[2:]
print('0'*(len(c)-len(x))+x)