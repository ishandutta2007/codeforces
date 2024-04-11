8.times{
	s=gets.chomp
	7.times{|i|
		if s[i]==s[i+1]
			print "NO"
			exit
		end
	}
}
print "YES"