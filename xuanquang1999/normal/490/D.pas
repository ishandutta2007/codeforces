const fi = '';
      fo = '';
var mA, nA, mB, nB, tu, mau, count: Qword;

function ucln(a, b: Qword): Qword;
begin
 if b = 0 then exit(a)
 else exit(ucln(b, a mod b));
end;

procedure Enter;
begin
 readln(mA, nA);
 readln(mB, nB);
end;

procedure Checktu(a, b: Qword);
begin
 while tu mod a = 0 do
  begin
   inc(count);
   if mA mod a = 0 then mA:=mA div a * b
   else nA:=nA div a * b;
   tu:=tu div a * b;
  end;
end;

procedure Checkmau(a, b: Qword);
begin
 while mau mod a = 0 do
  begin
   inc(count);
   if mB mod a = 0 then mB:=mB div a * b
   else nB:=nB div a * b;
   mau:=mau div a * b;
  end;
end;

procedure Work;
var u: Qword;
begin
 u:=ucln(mA*nA, mB*nB);
 tu:=mA*nA div u; mau:=mB*nB div u;
 Checktu(3, 2);
 Checkmau(3, 2);

 u:=ucln(tu, mau);
 tu:=tu div u; mau:=mau div u;
 Checktu(2, 1);
 Checkmau(2, 1);

 if tu = mau then
  begin
   writeln(count);
   writeln(mA, ' ', nA);
   writeln(mB, ' ', nB);
  end
 else writeln(-1);
end;

begin
 assign(input, fi); reset(input);
 assign(output, fo); rewrite(output);

 Enter;
 Work;

 close(input); close(output);
end.