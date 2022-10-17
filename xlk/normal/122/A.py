n=input()
print"YES"if any(set("47")>=set(str(i))and n%i==0 for i in range(1,n+1))else"NO"