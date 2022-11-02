<?php
$n = (int) fgets(STDIN);

$ve[0] = 6;
$ve[1] = 2;
$ve[2] = 5;
$ve[3] = 5;
$ve[4] = 4;
$ve[5] = 5;
$ve[6] = 6;
$ve[7] = 3;
$ve[8] = 7;
$ve[9] = 6;

$ok = 1;

$q = floor($n/2);

if ($n%2) {
  echo "7";
    $q--;
    
}

while ($q) {
  echo "1";
  $q--;
}
echo "\n";
?>