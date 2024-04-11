($l,$r,$k)=split' ',<>;
$nval=$r-$l+1;
if($nval<=10){
	$minxor=2e13;
	for $mask(0..(1<<$nval)-2){
		$setsize=$xor=0;
		for(0..$nval-1){
			next if $mask&1<<$_;
			$setsize++;
			$xor^=$l+$_;
		}
		next if $setsize>$k;
		($minmask,$minxor)=($mask,$xor) if $xor<$minxor;
	}
	@values=();
	for(0..$nval-1){
		next if $minmask&1<<$_;
		push @values,$l+$_;
	}
	print "$minxor\n",0+@values,"\n@values\n";
	exit;
}

sub solve2{
	$x=1+($l|1);
	print "1\n2\n@{[$x..$x+1]}\n";
}

if($k==1){
	print "$l\n1\n$l\n";
}elsif($k==2){
	solve2();
}elsif($k==3){
	$p2=1;
	$p2*=2 while $p2<=$l;
	$x=$p2*3/2;
	if($x>$r){
		solve2()
	}else{
		print "0\n3\n$l $x @{[$l^$x]}\n";
	}
}else{
	$x=1+($l|1);
	print "0\n4\n@{[$x..$x+3]}\n";
}