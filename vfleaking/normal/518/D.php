<?php
fscanf(STDIN, "%d %f %d", $n, $p, $t);

$f = array();
$f[] = array(1.0);
for ($i = 0; $i < $t; $i++) {
	$f[] = array();
	for ($j = 0; $j <= $i + 1 && $j <= $n; $j++) {
		$f[$i + 1][] = 0.0;
	}
	for ($j = 0; $j <= $i && $j <= $n; $j++) {
		$cur = $f[$i][$j];
		if ($j == $n) {
			$f[$i + 1][$j] += $cur;
		} else {
			$f[$i + 1][$j + 1] += $cur * $p;
			$f[$i + 1][$j] += $cur * (1 - $p);
		}
	}
}

$res = 0;
for ($j = 0; $j <= $t && $j <= $n; $j++) {
	$res += $f[$t][$j] * $j;
}

echo "$res\n";