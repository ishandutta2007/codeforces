if (__name__=='__main__'):
	dict0={}
	dict1={}
	val1=[]
	val=[]
	cnt=0
	while(1):
		s=input()
		s=s.strip()
		if(len(s)>2 and ord(s[0])==92 and s[1]=='b'):
			# print(s)
			val.append(s)
			# print('hi')
			break
		for i in range(0,len(s)):
			if(ord(s[i])==92):
				#print('hi')
				j=i+6
				res=""
				while(1):
					if(s[j]=='}'):
						dict0[res]=cnt
						val1.append(res)
						break
					res+=s[j]
					j+=1
				cnt+=1
	#val=[]
	i=1
	fl=0
	# print(cnt)
	# print(len(val))
	while(1):
		#print(i)
		s=input()
		s=s.strip()
		val.append(s)
		if i==cnt+1:
			break
		j=9
		res=""
		while(1):
			if(s[j]=='}'):
				#print(res,i)
				if(dict0[res]!=i-1):
					fl=1
				dict1[res]=i
				break
			res+=s[j]
			j+=1
		i+=1
	#print(len(val))
	if(fl==0):
		print("Correct")
	else:
		print("Incorrect")
		print(val[0])
		for i in range(1,cnt+1,1):
			res=val[dict1[val1[i-1]]]
			print(res)
		print(val[cnt+1])