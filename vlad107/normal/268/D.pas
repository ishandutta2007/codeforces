{$r-,q-,s-,i-,o+}
const
  base=1000000009;

var
  ni,ii,cr,i1,i2,i3,i4,res,kq,n,h,i,qqq,nkq,nq1,nq2,nq3,nq4:longint;
  used:array[0..33,0..33,0..33,0..33]of longint;
  qq1,qq2,qq3,qq4,q1,q2,q3,q4:array[0..500050]of longint;
  f,ff:array[0..33,0..33,0..33,0..33]of longint;
  
  procedure upd(i1,i2,i3,i4,cr:longint);inline;
    var
      t:array[1..5]of longint;
      j,i,tmp:longint;
      
    begin
      t[1]:=i1;t[2]:=i2;t[3]:=i3;t[4]:=i4;
      for i:=1 to 3 do
        for j:=1 to 3 do 
          if (t[j]>t[j+1])then begin
            tmp:=t[j];t[j]:=t[j+1];t[j+1]:=tmp;
          end;
      i1:=t[1];i2:=t[2];i3:=t[3];i4:=t[4];
      if (used[i1][i2][i3][i4]<>qqq)then begin
        inc(nkq);
        qq1[nkq]:=i1;
        qq2[nkq]:=i2;
        qq3[nkq]:=i3;
        qq4[nkq]:=i4;
        used[i1][i2][i3][i4]:=qqq;
        ff[i1][i2][i3][i4]:=0;
      end;
      inc(ff[i1][i2][i3][i4],cr);
      if (ff[i1][i2][i3][i4]>=base)then dec(ff[i1][i2][i3][i4],base);
    end;

begin
  //assign(input,'input.txt');reset(input);
  //assign(output,'output.txt');rewrite(output);
  read(n,h);
  kq:=1;
  q1[1]:=0;
  q2[1]:=0;
  q3[1]:=0;
  q4[1]:=0;
  f[0][0][0][0]:=1;
  fillchar(used,sizeof(used),$0);
  qqq:=0;res:=0;
  for ii:=1 to n do begin
    inc(qqq);
    nkq:=0;
    for i:=1 to kq do begin
      i1:=q1[i];i2:=q2[i];
      i3:=q3[i];i4:=q4[i];
      nq1:=i1+1;if (nq1>h)then nq1:=h+1;
      nq2:=i2+1;if (nq2>h)then nq2:=h+1;
      nq3:=i3+1;if (nq3>h)then nq3:=h+1;
      nq4:=i4+1;if (nq4>h)then nq4:=h+1;
      cr:=f[i1][i2][i3][i4];
      if (cr=0)then continue;
      
      if (nq1<>h+1)then ni:=0 else ni:=h+1;
      upd(ni,nq2,nq3,nq4,cr);
      if (nq2<>h+1)then ni:=0 else ni:=h+1;
      upd(nq1,ni,nq3,nq4,cr);
      if (nq3<>h+1)then ni:=0 else ni:=h+1;
      upd(nq1,nq2,ni,nq4,cr);
      if (nq4<>h+1)then ni:=0 else ni:=h+1;
      upd(nq1,nq2,nq3,ni,cr);
    end;
    kq:=nkq;
    for i:=1 to kq do begin
      q1[i]:=qq1[i];q2[i]:=qq2[i];
      q3[i]:=qq3[i];q4[i]:=qq4[i];
    end;
    for i:=1 to kq do f[q1[i]][q2[i]][q3[i]][q4[i]]:=ff[q1[i]][q2[i]][q3[i]][q4[i]];
  end;
  for i:=1 to kq do begin
    i1:=q1[i];i2:=q2[i];i3:=q3[i];i4:=q4[i];
    if (i1>=h)and(i2>=h)and(i3>=h)and(i4>=h)then continue;
    inc(res,f[i1][i2][i3][i4]);
    if (res>=base)then dec(res,base);
  end;
  writeln(res);
end.