a,b,z=raw_input(),raw_input(),0
for i in range(1,min(len(a),len(b))+1):
	if len(a)%i==0 and len(b)%i==0:
		if len(a)/i*a[:i]==a and len(b)/i*a[:i]==b:
			z+=1
print z