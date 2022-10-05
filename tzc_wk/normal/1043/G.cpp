__asm__(R"(	.file	"tmp4.cpp"
	.text
	.p2align 4,,15
	.def	__tcf_1;	.scl	3;	.type	32;	.endef
	.seh_proc	__tcf_1
__tcf_1:
.LFB11176:
	pushq	%rsi
	.seh_pushreg	%rsi
	pushq	%rbx
	.seh_pushreg	%rbx
	subq	$40, %rsp
	.seh_stackalloc	40
	.seh_endprologue
	leaq	4800096+pfac(%rip), %rbx
	leaq	-24+pfac(%rip), %rsi
	.p2align 4,,10
.L3:
	movq	(%rbx), %rcx
	testq	%rcx, %rcx
	je	.L2
	call	_ZdlPv
.L2:
	subq	$24, %rbx
	cmpq	%rsi, %rbx
	jne	.L3
	addq	$40, %rsp
	popq	%rbx
	popq	%rsi
	ret
	.seh_endproc
	.p2align 4,,15
	.def	__tcf_0;	.scl	3;	.type	32;	.endef
	.seh_proc	__tcf_0
__tcf_0:
.LFB11175:
	.seh_endprologue
	leaq	_ZStL8__ioinit(%rip), %rcx
	jmp	_ZNSt8ios_base4InitD1Ev
	.seh_endproc
	.section	.text$_Z5scanfPKcz,"x"
	.linkonce discard
	.p2align 4,,15
	.globl	_Z5scanfPKcz
	.def	_Z5scanfPKcz;	.scl	2;	.type	32;	.endef
	.seh_proc	_Z5scanfPKcz
_Z5scanfPKcz:
.LFB7:
	subq	$56, %rsp
	.seh_stackalloc	56
	.seh_endprologue
	movq	%rdx, 72(%rsp)
	leaq	72(%rsp), %rdx
	movq	%r8, 80(%rsp)
	movq	%r9, 88(%rsp)
	movq	%rdx, 40(%rsp)
	call	__mingw_vscanf
	addq	$56, %rsp
	ret
	.seh_endproc
	.section	.text$_ZN11SuffixArray4initEv,"x"
	.linkonce discard
	.align 2
	.p2align 4,,15
	.globl	_ZN11SuffixArray4initEv
	.def	_ZN11SuffixArray4initEv;	.scl	2;	.type	32;	.endef
	.seh_proc	_ZN11SuffixArray4initEv
_ZN11SuffixArray4initEv:
.LFB10044:
	pushq	%r15
	.seh_pushreg	%r15
	pushq	%r14
	.seh_pushreg	%r14
	pushq	%r13
	.seh_pushreg	%r13
	pushq	%r12
	.seh_pushreg	%r12
	pushq	%rbp
	.seh_pushreg	%rbp
	pushq	%rdi
	.seh_pushreg	%rdi
	pushq	%rsi
	.seh_pushreg	%rsi
	pushq	%rbx
	.seh_pushreg	%rbx
	subq	$40, %rsp
	.seh_stackalloc	40
	.seh_endprologue
	cmpb	$0, _ZGVZN11SuffixArray5getsaEvE1x(%rip)
	movq	%rcx, %rbx
	je	.L104
.L13:
	leaq	3400088(%rbx), %rbp
	xorl	%edx, %edx
	movl	$800020, %r8d
	movq	%rbp, %rcx
	call	memset
	movl	n(%rip), %edi
	testl	%edi, %edi
	jle	.L19
	leal	-1(%rdi), %edx
	leaq	1(%rbx), %rax
	leaq	2(%rbx,%rdx), %rcx
	.p2align 4,,10
.L18:
	movsbq	(%rax), %rdx
	addq	$1, %rax
	addl	$1, 3400088(%rbx,%rdx,4)
	cmpq	%rcx, %rax
	jne	.L18
.L19:
	leaq	3400092(%rbx), %rsi
	leaq	3400580(%rbx), %rcx
	movq	%rsi, %rax
	.p2align 4,,10
.L17:
	movl	-4(%rax), %edx
	addl	%edx, (%rax)
	addq	$4, %rax
	cmpq	%rcx, %rax
	jne	.L17
	testl	%edi, %edi
	je	.L63
	movl	%edi, %eax
	.p2align 4,,10
.L21:
	movslq	%eax, %rdx
	movsbq	(%rbx,%rdx), %rdx
	leaq	(%rbx,%rdx,4), %rcx
	movslq	3400088(%rcx), %rdx
	leal	-1(%rdx), %r8d
	movl	%r8d, 3400088(%rcx)
	movl	%eax, 1000028(%rbx,%rdx,4)
	subl	$1, %eax
	jne	.L21
	testl	%edi, %edi
	jle	.L20
	leal	-1(%rdi), %edx
	leaq	1000032(%rbx), %r12
	leaq	1000036(%rbx,%rdx,4), %r9
	movq	%r12, %rax
	xorl	%edx, %edx
	.p2align 4,,10
.L24:
	movslq	-4(%rax), %r8
	movslq	(%rax), %rcx
	movzbl	(%rbx,%r8), %r11d
	xorl	%r8d, %r8d
	cmpb	%r11b, (%rbx,%rcx)
	setne	%r8b
	addq	$4, %rax
	addl	%r8d, %edx
	cmpq	%r9, %rax
	movl	%edx, 200008(%rbx,%rcx,4)
	jne	.L24
	movl	%edi, %r15d
	movl	$122, %r14d
	movl	$1, %r13d
.L47:
	testl	%r15d, %r15d
	jle	.L49
	movl	n(%rip), %edi
	leaq	200012(%rbx), %r8
	leaq	_ZZN11SuffixArray5getsaEvE1x(%rip), %rdx
	movl	$1, %eax
	jmp	.L28
	.p2align 4,,10
.L106:
	movslq	%ecx, %rcx
	movl	(%r8), %r9d
	addl	$1, %eax
	movl	200008(%rbx,%rcx,4), %ecx
	addq	$4, %r8
	addq	$8, %rdx
	movl	%r9d, (%rdx)
	movl	%ecx, 4(%rdx)
	cmpl	%eax, %edi
	jl	.L105
.L64:
	movl	%edi, %r15d
.L28:
	leal	(%rax,%r13), %ecx
	cmpl	%ecx, %r15d
	jge	.L106
	movl	(%r8), %ecx
	addl	$1, %eax
	movl	$0, 12(%rdx)
	addq	$4, %r8
	addq	$8, %rdx
	movl	%ecx, (%rdx)
	cmpl	%eax, %edi
	jge	.L64
.L105:
	movl	$800020, %r8d
	xorl	%edx, %edx
	movq	%rbp, %rcx
	call	memset
	movl	%edi, %r8d
	subl	%r13d, %r8d
	leal	1(%r8), %eax
	cmpl	%eax, %edi
	jl	.L107
.L62:
	leaq	2600072(%rbx), %rdx
	leal	1(%rdi), %ecx
	.p2align 4,,10
.L30:
	movl	%eax, (%rdx)
	addl	$1, %eax
	addq	$4, %rdx
	cmpl	%ecx, %eax
	jne	.L30
	movl	%edi, %ecx
	subl	%r8d, %ecx
.L29:
	testl	%edi, %edi
	jle	.L66
	leal	-1(%rdi), %r9d
	movq	%r12, %rax
	leaq	1000036(%rbx,%r9,4), %r8
	.p2align 4,,10
.L33:
	movl	(%rax), %edx
	cmpl	%r13d, %edx
	jle	.L32
	addl	$1, %ecx
	subl	%r13d, %edx
	movslq	%ecx, %r10
	movl	%edx, 2600068(%rbx,%r10,4)
.L32:
	addq	$4, %rax
	cmpq	%r8, %rax
	jne	.L33
	leaq	_ZZN11SuffixArray5getsaEvE1x(%rip), %rcx
	leaq	8+_ZZN11SuffixArray5getsaEvE1x(%rip), %rax
	leaq	16(%rcx,%r9,8), %r8
	.p2align 4,,10
.L34:
	movslq	(%rax), %rdx
	addq	$8, %rax
	addl	$1, 3400088(%rbx,%rdx,4)
	cmpq	%r8, %rax
	jne	.L34
	testl	%r14d, %r14d
	jle	.L37
.L36:
	movq	%rsi, %rax
	movl	$1, %edx
	.p2align 4,,10
.L39:
	addl	$1, %edx
	movl	-4(%rax), %ecx
	addl	%ecx, (%rax)
	addq	$4, %rax
	cmpl	%r14d, %edx
	jle	.L39
.L40:
	testl	%edi, %edi
	je	.L38
	leaq	_ZZN11SuffixArray5getsaEvE1x(%rip), %rcx
.L37:
	movl	%edi, %edx
	.p2align 4,,10
.L41:
	movslq	%edx, %rax
	subl	$1, %edx
	leaq	(%rbx,%rax,4), %r8
	movslq	2600068(%r8), %rax
	movslq	(%rcx,%rax,8), %rax
	leaq	(%rbx,%rax,4), %r9
	movslq	3400088(%r9), %rax
	leal	-1(%rax), %r10d
	movl	%r10d, 3400088(%r9)
	movl	2600068(%r8), %r8d
	movl	%r8d, 1000028(%rbx,%rax,4)
	jne	.L41
	testl	%edi, %edi
	jle	.L68
	leal	-1(%rdi), %edx
	leaq	1000028(%rbx), %rax
	xorl	%r14d, %r14d
	leaq	1000032(%rbx,%rdx,4), %r10
	jmp	.L44
	.p2align 4,,10
.L43:
	addl	$1, %r14d
.L59:
	addq	$4, %rax
	movl	%r14d, 200008(%rbx,%rdx,4)
	cmpq	%r10, %rax
	je	.L108
.L44:
	movslq	4(%rax), %rdx
	movslq	(%rax), %r8
	leaq	_ZZN11SuffixArray5getsaEvE1x(%rip), %r9
	movl	(%rcx,%r8,8), %r15d
	cmpl	%r15d, (%rcx,%rdx,8)
	jne	.L43
	movl	4(%r9,%r8,8), %r11d
	cmpl	%r11d, 4(%r9,%rdx,8)
	jne	.L43
	jmp	.L59
.L108:
	cmpl	%r14d, %edi
	je	.L38
.L45:
	movl	n(%rip), %edi
	addl	%r13d, %r13d
	cmpl	%edi, %r13d
	movl	%edi, %r15d
	jle	.L47
.L48:
	testl	%edi, %edi
	jle	.L20
	leaq	200012(%rbx), %rsi
	leal	1(%rdi), %ebp
	xorl	%r10d, %r10d
	movl	$1, %r11d
	.p2align 4,,10
.L54:
	movslq	(%rsi), %rax
	cmpl	$1, %eax
	je	.L50
	cmpl	$1, %r10d
	leaq	(%rbx,%rax,4), %r12
	adcl	$-1, %r10d
	leal	(%r10,%r11), %edx
	movl	1000024(%r12), %eax
	cmpl	%edx, %edi
	jl	.L52
	leal	(%rax,%r10), %ecx
	cmpl	%ecx, %edi
	jl	.L52
	movslq	%ecx, %rcx
	movslq	%edx, %rdx
	movzbl	(%rbx,%rcx), %ecx
	cmpb	%cl, (%rbx,%rdx)
	jne	.L52
	leal	1(%r10), %r9d
	leal	(%r9,%r11), %edx
	addl	%r9d, %eax
	jmp	.L53
	.p2align 4,,10
.L109:
	cmpl	%eax, %edi
	movslq	%eax, %r8
	jl	.L52
	movzbl	(%rbx,%r8), %r15d
	addl	$1, %edx
	addl	$1, %eax
	cmpb	%r15b, (%rbx,%rcx)
	jne	.L52
	addl	$1, %r9d
.L53:
	cmpl	%edx, %edi
	movl	%r9d, %r10d
	movslq	%edx, %rcx
	jge	.L109
.L52:
	movl	%r10d, 1800048(%r12)
.L50:
	addl	$1, %r11d
	addq	$4, %rsi
	cmpl	%ebp, %r11d
	jne	.L54
	leal	-1(%rdi), %edx
	leaq	1800052(%rbx), %rax
	leaq	1800056(%rbx,%rdx,4), %rcx
	.p2align 4,,10
.L55:
	movl	(%rax), %edx
	addq	$4, %rax
	movl	%edx, 2400056(%rax)
	cmpq	%rcx, %rax
	jne	.L55
.L20:
	leal	2(%rdi), %r14d
	xorl	%r11d, %r11d
	movl	$1, %ebp
	movl	$1, %r12d
	movl	$4200112, %r15d
	movl	$800020, %r13d
	.p2align 4,,10
.L60:
	movl	%r12d, %edx
	movl	%ebp, %ecx
	sall	%cl, %edx
	cmpl	%edi, %edx
	jg	.L58
	leal	-1(%rbp), %ecx
	movl	%r12d, %r9d
	movq	%r15, %rax
	movl	%r14d, %esi
	subq	%r11, %rax
	movslq	%ecx, %r10
	sall	%cl, %r9d
	subl	%edx, %esi
	imulq	$200005, %r10, %r10
	movq	%r13, %rcx
	leal	1(%r9), %r8d
	addq	%rbx, %rax
	addl	%r9d, %esi
	subq	%r11, %rcx
	.p2align 4,,10
.L56:
	movslq	%r8d, %rdx
	leaq	(%rax,%r11), %r9
	leaq	1050024(%rdx,%r10), %rdx
	movl	12(%rbx,%rdx,4), %edx
	cmpl	%edx, (%rax)
	cmovle	(%rax), %edx
	addl	$1, %r8d
	addq	$4, %rax
	cmpl	%esi, %r8d
	movl	%edx, (%r9,%rcx)
	jne	.L56
.L58:
	addl	$1, %ebp
	subq	$800020, %r11
	cmpl	$19, %ebp
	jne	.L60
	addq	$40, %rsp
	popq	%rbx
	popq	%rsi
	popq	%rdi
	popq	%rbp
	popq	%r12
	popq	%r13
	popq	%r14
	popq	%r15
	ret
.L49:
	movl	$800020, %r8d
	xorl	%edx, %edx
	movq	%rbp, %rcx
	call	memset
	movl	%r15d, %r8d
	subl	%r13d, %r8d
	leal	1(%r8), %eax
	cmpl	%eax, %r15d
	jl	.L31
	movl	%r15d, %edi
	jmp	.L62
.L38:
	movl	n(%rip), %edi
	jmp	.L48
.L104:
	leaq	_ZGVZN11SuffixArray5getsaEvE1x(%rip), %rcx
	call	__cxa_guard_acquire
	testl	%eax, %eax
	je	.L13
	leaq	_ZZN11SuffixArray5getsaEvE1x(%rip), %rax
	leaq	1600040+_ZZN11SuffixArray5getsaEvE1x(%rip), %rdx
.L15:
	movl	$0, (%rax)
	movl	$0, 4(%rax)
	addq	$8, %rax
	cmpq	%rdx, %rax
	jne	.L15
	leaq	_ZGVZN11SuffixArray5getsaEvE1x(%rip), %rcx
	call	__cxa_guard_release
	jmp	.L13
.L66:
	movl	%edi, %r15d
.L31:
	testl	%r14d, %r14d
	movl	%r15d, %edi
	jg	.L36
	jmp	.L40
	.p2align 4,,10
.L107:
	xorl	%ecx, %ecx
	jmp	.L29
.L68:
	xorl	%r14d, %r14d
	jmp	.L45
.L63:
	xorl	%edi, %edi
	jmp	.L20
	.seh_endproc
	.text
	.p2align 4,,15
	.globl	_Z6getlcpii
	.def	_Z6getlcpii;	.scl	2;	.type	32;	.endef
	.seh_proc	_Z6getlcpii
_Z6getlcpii:
.LFB10045:
	.seh_endprologue
	cmpl	%edx, %ecx
	je	.L114
	leaq	fw(%rip), %r8
	movslq	%ecx, %rcx
	movslq	%edx, %rdx
	movl	200008(%r8,%rcx,4), %ecx
	movl	200008(%r8,%rdx,4), %eax
	cmpl	%eax, %ecx
	jle	.L113
	movl	%ecx, %edx
	movl	%eax, %ecx
	movl	%edx, %eax
.L113:
	movl	%eax, %r10d
	leaq	hib(%rip), %r9
	leal	1(%rcx), %edx
	subl	%ecx, %r10d
	movslq	%r10d, %rcx
	movslq	%edx, %rdx
	movslq	(%r9,%rcx,4), %rcx
	movl	$1, %r9d
	sall	%cl, %r9d
	imulq	$200005, %rcx, %rcx
	subl	%r9d, %eax
	addl	$1, %eax
	cltq
	leaq	1050024(%rax,%rcx), %r9
	leaq	1050024(%rcx,%rdx), %rax
	movl	12(%r8,%rax,4), %eax
	cmpl	%eax, 12(%r8,%r9,4)
	cmovle	12(%r8,%r9,4), %eax
	ret
	.p2align 4,,10
.L114:
	movl	n(%rip), %eax
	subl	%ecx, %eax
	addl	$1, %eax
	ret
	.seh_endproc
	.p2align 4,,15
	.globl	_Z6getlcsii
	.def	_Z6getlcsii;	.scl	2;	.type	32;	.endef
	.seh_proc	_Z6getlcsii
_Z6getlcsii:
.LFB10046:
	.seh_endprologue
	movl	n(%rip), %eax
	movl	%eax, %r10d
	movl	%eax, %r11d
	subl	%edx, %r10d
	subl	%ecx, %r11d
	movl	%r10d, %edx
	movl	%r11d, %ecx
	addl	$1, %edx
	addl	$1, %ecx
	cmpl	%ecx, %edx
	je	.L119
	leaq	bk(%rip), %r8
	movslq	%ecx, %rcx
	movslq	%edx, %rdx
	movl	200008(%r8,%rcx,4), %ecx
	movl	200008(%r8,%rdx,4), %eax
	cmpl	%eax, %ecx
	jle	.L118
	movl	%ecx, %edx
	movl	%eax, %ecx
	movl	%edx, %eax
.L118:
	movl	%eax, %r10d
	leaq	hib(%rip), %r9
	leal	1(%rcx), %edx
	subl	%ecx, %r10d
	movslq	%r10d, %rcx
	movslq	%edx, %rdx
	movslq	(%r9,%rcx,4), %rcx
	movl	$1, %r9d
	sall	%cl, %r9d
	imulq	$200005, %rcx, %rcx
	subl	%r9d, %eax
	addl	$1, %eax
	cltq
	leaq	1050024(%rax,%rcx), %r9
	leaq	1050024(%rcx,%rdx), %rax
	movl	12(%r8,%rax,4), %eax
	cmpl	%eax, 12(%r8,%r9,4)
	cmovle	12(%r8,%r9,4), %eax
	ret
	.p2align 4,,10
.L119:
	subl	%edx, %eax
	addl	$1, %eax
	ret
	.seh_endproc
	.p2align 4,,15
	.globl	_Z9check_equiiii
	.def	_Z9check_equiiii;	.scl	2;	.type	32;	.endef
	.seh_proc	_Z9check_equiiii
_Z9check_equiiii:
.LFB10047:
	.seh_endprologue
	subl	%ecx, %edx
	cmpl	%r8d, %ecx
	je	.L124
	leaq	fw(%rip), %r9
	movslq	%ecx, %rcx
	movslq	%r8d, %r8
	movl	200008(%r9,%rcx,4), %ecx
	movl	200008(%r9,%r8,4), %eax
	cmpl	%eax, %ecx
	jg	.L125
.L123:
	movl	%eax, %r11d
	leaq	hib(%rip), %r10
	leal	1(%rcx), %r8d
	subl	%ecx, %r11d
	movslq	%r11d, %rcx
	movslq	%r8d, %r8
	movslq	(%r10,%rcx,4), %rcx
	movl	$1, %r10d
	sall	%cl, %r10d
	imulq	$200005, %rcx, %rcx
	subl	%r10d, %eax
	addl	$1, %eax
	cltq
	leaq	1050024(%rax,%rcx), %r10
	leaq	1050024(%rcx,%r8), %rax
	movl	12(%r9,%rax,4), %eax
	cmpl	%eax, 12(%r9,%r10,4)
	cmovle	12(%r9,%r10,4), %eax
	cmpl	%eax, %edx
	setl	%al
	ret
	.p2align 4,,10
.L125:
	movl	%ecx, %r8d
	movl	%eax, %ecx
	movl	%r8d, %eax
	jmp	.L123
	.p2align 4,,10
.L124:
	movl	n(%rip), %eax
	subl	%ecx, %eax
	addl	$1, %eax
	cmpl	%eax, %edx
	setl	%al
	ret
	.seh_endproc
	.p2align 4,,15
	.globl	_Z6check0ii
	.def	_Z6check0ii;	.scl	2;	.type	32;	.endef
	.seh_proc	_Z6check0ii
_Z6check0ii:
.LFB10048:
	.seh_endprologue
	leaq	sum(%rip), %r9
	movslq	%edx, %rdx
	subl	$1, %ecx
	leaq	(%rdx,%rdx,2), %rax
	movslq	%ecx, %rcx
	leaq	(%rdx,%rax,4), %r8
	imulq	$-104, %rdx, %rdx
	salq	$3, %r8
	leaq	(%r8,%r9), %rax
	leaq	104(%r9,%r8), %r10
	leaq	(%rcx,%rcx,2), %r8
	leaq	(%rcx,%r8,4), %r9
	salq	$3, %r9
	jmp	.L128
	.p2align 4,,10
.L132:
	addq	$4, %rax
	cmpq	%r10, %rax
	je	.L131
.L128:
	leaq	(%rax,%rdx), %r8
	movl	(%rax), %ecx
	subl	(%r8,%r9), %ecx
	cmpl	$1, %ecx
	jle	.L132
	xorl	%eax, %eax
	ret
	.p2align 4,,10
.L131:
	movl	$1, %eax
	ret
	.seh_endproc
	.p2align 4,,15
	.globl	_Z6check1ii
	.def	_Z6check1ii;	.scl	2;	.type	32;	.endef
	.seh_proc	_Z6check1ii
_Z6check1ii:
.LFB10049:
	pushq	%r14
	.seh_pushreg	%r14
	pushq	%r13
	.seh_pushreg	%r13
	pushq	%r12
	.seh_pushreg	%r12
	pushq	%rbp
	.seh_pushreg	%rbp
	pushq	%rdi
	.seh_pushreg	%rdi
	pushq	%rsi
	.seh_pushreg	%rsi
	pushq	%rbx
	.seh_pushreg	%rbx
	.seh_endprologue
	movl	%edx, %ebx
	movl	%edx, %esi
	movl	%ecx, %r11d
	subl	%ecx, %ebx
	addl	$1, %ebx
	movslq	%ebx, %rax
	leaq	(%rax,%rax,2), %rdx
	leaq	pfac(%rip), %rax
	leaq	(%rax,%rdx,8), %rax
	movq	(%rax), %r9
	movq	8(%rax), %rdi
	cmpq	%r9, %rdi
	je	.L138
	movl	n(%rip), %r13d
	movslq	%ecx, %r12
	movl	$1, %ebp
	subl	%ecx, %r13d
	addl	$1, %r13d
	jmp	.L137
	.p2align 4,,10
.L142:
	leaq	fw(%rip), %r10
	movslq	%edx, %rdx
	movl	200008(%r10,%r12,4), %ecx
	movl	200008(%r10,%rdx,4), %r8d
	cmpl	%r8d, %ecx
	jle	.L136
	movl	%ecx, %edx
	movl	%r8d, %ecx
	movl	%edx, %r8d
.L136:
	movl	%r8d, %r14d
	leal	1(%rcx), %edx
	subl	%ecx, %r14d
	movslq	%r14d, %rcx
	leaq	hib(%rip), %r14
	movslq	%edx, %rdx
	movslq	(%r14,%rcx,4), %rcx
	movl	%ebp, %r14d
	sall	%cl, %r14d
	imulq	$200005, %rcx, %rcx
	subl	%r14d, %r8d
	addl	$1, %r8d
	movslq	%r8d, %r8
	leaq	1050024(%r8,%rcx), %r8
	leaq	1050024(%rcx,%rdx), %rdx
	movl	12(%r10,%rdx,4), %edx
	cmpl	%edx, 12(%r10,%r8,4)
	cmovle	12(%r10,%r8,4), %edx
	cmpl	%edx, %eax
	jl	.L140
.L143:
	addq	$4, %r9
	cmpq	%r9, %rdi
	je	.L138
.L137:
	movl	%ebx, %eax
	movl	%esi, %ecx
	cltd
	idivl	(%r9)
	leal	(%rax,%r11), %edx
	subl	%eax, %ecx
	movl	%ecx, %eax
	subl	%r11d, %eax
	cmpl	%edx, %r11d
	jne	.L142
	movl	%r13d, %edx
	cmpl	%edx, %eax
	jge	.L143
.L140:
	movl	$1, %eax
	popq	%rbx
	popq	%rsi
	popq	%rdi
	popq	%rbp
	popq	%r12
	popq	%r13
	popq	%r14
	ret
	.p2align 4,,10
.L138:
	xorl	%eax, %eax
	popq	%rbx
	popq	%rsi
	popq	%rdi
	popq	%rbp
	popq	%r12
	popq	%r13
	popq	%r14
	ret
	.seh_endproc
	.p2align 4,,15
	.globl	_Z9query_ritii
	.def	_Z9query_ritii;	.scl	2;	.type	32;	.endef
	.seh_proc	_Z9query_ritii
_Z9query_ritii:
.LFB10054:
	.seh_endprologue
	movl	$1, %r10d
	leaq	st_rit(%rip), %r9
	movslq	%ecx, %r8
	movl	%edx, %eax
	leaq	hib(%rip), %rcx
	subl	%r8d, %eax
	addl	$1, %eax
	cltq
	movslq	(%rcx,%rax,4), %rax
	movq	%rax, %rcx
	sall	%cl, %r10d
	imulq	$200005, %rax, %rax
	subl	%r10d, %edx
	addl	$1, %edx
	movslq	%edx, %rdx
	addq	%rax, %rdx
	addq	%r8, %rax
	movl	(%r9,%rax,4), %eax
	cmpl	%eax, (%r9,%rdx,4)
	cmovge	(%r9,%rdx,4), %eax
	ret
	.seh_endproc
	.p2align 4,,15
	.globl	_Z12get_shortestii
	.def	_Z12get_shortestii;	.scl	2;	.type	32;	.endef
	.seh_proc	_Z12get_shortestii
_Z12get_shortestii:
.LFB10055:
	pushq	%r15
	.seh_pushreg	%r15
	pushq	%r14
	.seh_pushreg	%r14
	pushq	%r13
	.seh_pushreg	%r13
	pushq	%r12
	.seh_pushreg	%r12
	pushq	%rbp
	.seh_pushreg	%rbp
	pushq	%rdi
	.seh_pushreg	%rdi
	pushq	%rsi
	.seh_pushreg	%rsi
	pushq	%rbx
	.seh_pushreg	%rbx
	subq	$24, %rsp
	.seh_stackalloc	24
	.seh_endprologue
	movl	lim(%rip), %r9d
	movl	n(%rip), %r14d
	movl	%edx, %ebp
	movl	%ecx, %r10d
	subl	%ecx, %ebp
	addl	$1, %ebp
	cmpl	%r9d, %ebp
	cmovg	%r9d, %ebp
	testl	%ebp, %ebp
	jle	.L146
	movl	%r14d, %eax
	movl	%edx, %ebx
	movslq	%ecx, %r13
	subl	%ecx, %eax
	movl	$1, %r12d
	addl	$1, %eax
	movl	%eax, 12(%rsp)
	movl	$1, %eax
	jmp	.L150
	.p2align 4,,10
.L170:
	leaq	fw(%rip), %r11
	movslq	%ebx, %r8
	movl	200008(%r11,%r13,4), %ecx
	movl	200008(%r11,%r8,4), %r8d
	cmpl	%r8d, %ecx
	jle	.L148
	movl	%ecx, %esi
	movl	%r8d, %ecx
	movl	%esi, %r8d
.L148:
	movl	%r8d, %r15d
	leal	1(%rcx), %esi
	subl	%ecx, %r15d
	movslq	%r15d, %rcx
	leaq	hib(%rip), %r15
	movslq	%esi, %rsi
	movslq	(%r15,%rcx,4), %rcx
	movl	%r12d, %r15d
	sall	%cl, %r15d
	imulq	$200005, %rcx, %rcx
	subl	%r15d, %r8d
	addl	$1, %r8d
	movslq	%r8d, %r8
	leaq	1050024(%r8,%rcx), %r8
	leaq	1050024(%rcx,%rsi), %rcx
	movl	12(%r11,%rcx,4), %ecx
	cmpl	%ecx, 12(%r11,%r8,4)
	cmovle	12(%r11,%r8,4), %ecx
	cmpl	%edi, %ecx
	jg	.L149
.L171:
	addl	$1, %eax
	subl	$1, %ebx
	cmpl	%ebp, %eax
	jg	.L146
.L150:
	cmpl	%ebx, %r10d
	leal	-1(%rax), %edi
	jne	.L170
	movl	12(%rsp), %ecx
	cmpl	%edi, %ecx
	jle	.L171
	.p2align 4,,10
.L149:
	addq	$24, %rsp
	popq	%rbx
	popq	%rsi
	popq	%rdi
	popq	%rbp
	popq	%r12
	popq	%r13
	popq	%r14
	popq	%r15
	ret
	.p2align 4,,10
.L146:
	leaq	fw(%rip), %rbx
	movslq	%r10d, %rax
	movl	200008(%rbx,%rax,4), %edi
	movl	$1, %eax
	movl	%edi, %r11d
	subl	%r9d, %r11d
	testl	%r11d, %r11d
	cmovle	%eax, %r11d
	addl	%edi, %r9d
	cmpl	%r14d, %r9d
	cmovg	%r14d, %r9d
	cmpl	%r9d, %r11d
	jg	.L158
	leal	1(%r9), %ebp
	movl	$1061109567, %eax
	movl	$1, %r12d
	.p2align 4,,10
.L155:
	movslq	%r11d, %rcx
	movl	1000028(%rbx,%rcx,4), %r9d
	cmpl	%edx, %r9d
	jge	.L153
	cmpl	%r9d, %r10d
	jge	.L153
	leaq	fw(%rip), %r8
	movslq	%r9d, %rcx
	movl	200008(%r8,%rcx,4), %r8d
	movl	%edi, %ecx
	cmpl	%r8d, %edi
	jle	.L154
	movl	%r8d, %ecx
	movl	%edi, %r8d
.L154:
	movl	%r8d, %r14d
	leaq	hib(%rip), %r13
	leal	1(%rcx), %esi
	subl	%ecx, %r14d
	movl	%edx, %r15d
	movslq	%r14d, %rcx
	movslq	%esi, %rsi
	subl	%r9d, %r15d
	movslq	0(%r13,%rcx,4), %rcx
	movl	%r12d, %r13d
	movl	%r15d, %r9d
	sall	%cl, %r13d
	imulq	$200005, %rcx, %rcx
	subl	%r13d, %r8d
	addl	$1, %r8d
	movslq	%r8d, %r8
	leaq	1050024(%r8,%rcx), %r8
	leaq	1050024(%rcx,%rsi), %rcx
	movl	12(%rbx,%rcx,4), %ecx
	cmpl	%ecx, 12(%rbx,%r8,4)
	cmovle	12(%rbx,%r8,4), %ecx
	cmpl	%ecx, %r15d
	jge	.L153
	addl	$1, %r9d
	cmpl	%r9d, %eax
	cmovg	%r9d, %eax
.L153:
	addl	$1, %r11d
	cmpl	%ebp, %r11d
	jne	.L155
	jmp	.L149
.L158:
	movl	$1061109567, %eax
	jmp	.L149
	.seh_endproc
	.p2align 4,,15
	.globl	_Z6check2ii
	.def	_Z6check2ii;	.scl	2;	.type	32;	.endef
	.seh_proc	_Z6check2ii
_Z6check2ii:
.LFB10056:
	pushq	%rsi
	.seh_pushreg	%rsi
	pushq	%rbx
	.seh_pushreg	%rbx
	subq	$40, %rsp
	.seh_stackalloc	40
	.seh_endprologue
	leaq	lft(%rip), %r8
	movl	$1, %eax
	movslq	%ecx, %r9
	cmpl	%edx, (%r8,%r9,4)
	jle	.L173
	leaq	rit(%rip), %r8
	movslq	%edx, %r9
	cmpl	(%r8,%r9,4), %ecx
	jle	.L173
	movl	%edx, %ebx
	movl	%ecx, %esi
	subl	%esi, %ebx
	call	_Z12get_shortestii
	movl	%ebx, %edx
	addl	%eax, %eax
	addl	$1, %edx
	cmpl	%edx, %eax
	setle	%al
.L173:
	addq	$40, %rsp
	popq	%rbx
	popq	%rsi
	ret
	.seh_endproc
	.p2align 4,,15
	.globl	_Z6check3ii
	.def	_Z6check3ii;	.scl	2;	.type	32;	.endef
	.seh_proc	_Z6check3ii
_Z6check3ii:
.LFB10057:
	pushq	%rdi
	.seh_pushreg	%rdi
	pushq	%rsi
	.seh_pushreg	%rsi
	pushq	%rbx
	.seh_pushreg	%rbx
	.seh_endprologue
	movl	$1, %r8d
	leaq	st_rit(%rip), %r11
	movslq	%ecx, %r10
	movl	%edx, %eax
	leaq	hib(%rip), %rcx
	subl	%r10d, %eax
	movq	%r10, %r9
	addl	$1, %eax
	cltq
	movl	(%rcx,%rax,4), %ecx
	movl	%edx, %eax
	sall	%cl, %r8d
	subl	%r8d, %eax
	movl	%eax, %r8d
	movslq	%ecx, %rax
	imulq	$200005, %rax, %rax
	addl	$1, %r8d
	movslq	%r8d, %r8
	addq	%rax, %r8
	addq	%r10, %rax
	movl	(%r11,%rax,4), %eax
	cmpl	%eax, (%r11,%r8,4)
	cmovge	(%r11,%r8,4), %eax
	movl	%eax, %ecx
	movl	$1, %eax
	cmpl	%ecx, %r10d
	jle	.L177
	leaq	str(%rip), %rbx
	movslq	%edx, %r8
	leaq	(%r10,%r10,2), %rdi
	leaq	(%r8,%r8,2), %rsi
	leaq	sum(%rip), %r11
	movsbl	(%rbx,%r10), %ecx
	leaq	(%r10,%rdi,4), %r10
	leaq	(%r8,%rsi,4), %rsi
	subl	$97, %ecx
	movslq	%ecx, %rcx
	leaq	(%rcx,%rsi,2), %rsi
	leaq	(%rcx,%r10,2), %rcx
	movl	(%r11,%rcx,4), %edi
	cmpl	%edi, (%r11,%rsi,4)
	je	.L180
.L177:
	popq	%rbx
	popq	%rsi
	popq	%rdi
	ret
	.p2align 4,,10
.L180:
	subl	$1, %edx
	movsbl	(%rbx,%r8), %eax
	subl	$1, %r9d
	movslq	%edx, %rdx
	movslq	%r9d, %r9
	leaq	(%rdx,%rdx,2), %rcx
	leaq	(%rdx,%rcx,4), %rdx
	leaq	(%r9,%r9,2), %rcx
	subl	$97, %eax
	cltq
	leaq	(%r9,%rcx,4), %rcx
	leaq	(%rax,%rdx,2), %rdx
	leaq	(%rax,%rcx,2), %rax
	movl	(%r11,%rax,4), %eax
	cmpl	%eax, (%r11,%rdx,4)
	setne	%al
	popq	%rbx
	popq	%rsi
	popq	%rdi
	ret
	.seh_endproc
	.section	.text$_ZNSt6vectorIiSaIiEE19_M_emplace_back_auxIIRKiEEEvDpOT_,"x"
	.linkonce discard
	.align 2
	.p2align 4,,15
	.globl	_ZNSt6vectorIiSaIiEE19_M_emplace_back_auxIIRKiEEEvDpOT_
	.def	_ZNSt6vectorIiSaIiEE19_M_emplace_back_auxIIRKiEEEvDpOT_;	.scl	2;	.type	32;	.endef
	.seh_proc	_ZNSt6vectorIiSaIiEE19_M_emplace_back_auxIIRKiEEEvDpOT_
_ZNSt6vectorIiSaIiEE19_M_emplace_back_auxIIRKiEEEvDpOT_:
.LFB10655:
	pushq	%rbp
	.seh_pushreg	%rbp
	pushq	%rdi
	.seh_pushreg	%rdi
	pushq	%rsi
	.seh_pushreg	%rsi
	pushq	%rbx
	.seh_pushreg	%rbx
	subq	$56, %rsp
	.seh_stackalloc	56
	.seh_endprologue
	movq	8(%rcx), %r10
	movq	(%rcx), %r11
	movq	%rcx, %rsi
	movq	%r10, %rax
	subq	%r11, %rax
	movq	%rax, %rbx
	sarq	$2, %rbx
	testq	%rbx, %rbx
	je	.L189
	leaq	(%rbx,%rbx), %rcx
	cmpq	%rcx, %rbx
	jbe	.L203
.L191:
	movq	$-4, %rbx
.L182:
	movq	%rbx, %rcx
	movq	%rdx, 40(%rsp)
	call	_Znwy
	movq	8(%rsi), %r10
	movq	(%rsi), %r11
	movq	%rax, %rdi
	movq	40(%rsp), %rdx
	leaq	4(%rdi), %rbp
	movq	%r10, %rax
	subq	%r11, %rax
.L183:
	addq	%rdi, %rax
	movl	(%rdx), %edx
	je	.L184
	movl	%edx, (%rax)
.L184:
	cmpq	%r10, %r11
	je	.L185
	movq	%r11, %rdx
	movq	%rdi, %r8
	.p2align 4,,10
.L187:
	testq	%r8, %r8
	movl	(%rdx), %r9d
	je	.L186
	movl	%r9d, (%r8)
.L186:
	addq	$4, %rdx
	addq	$4, %r8
	cmpq	%rdx, %r10
	jne	.L187
	leaq	4(%r11), %rax
	subq	%rax, %r10
	shrq	$2, %r10
	leaq	8(%rdi,%r10,4), %rbp
.L185:
	testq	%r11, %r11
	je	.L188
	movq	%r11, %rcx
	call	_ZdlPv
.L188:
	addq	%rdi, %rbx
	movq	%rdi, (%rsi)
	movq	%rbp, 8(%rsi)
	movq	%rbx, 16(%rsi)
	addq	$56, %rsp
	popq	%rbx
	popq	%rsi
	popq	%rdi
	popq	%rbp
	ret
	.p2align 4,,10
.L189:
	movl	$4, %ebx
	jmp	.L182
.L203:
	movabsq	$4611686018427387903, %r8
	cmpq	%r8, %rcx
	ja	.L191
	salq	$3, %rbx
	testq	%rcx, %rcx
	jne	.L182
	movl	$4, %ebp
	xorl	%edi, %edi
	jmp	.L183
	.seh_endproc
	.weak	_ZNSt6vectorIiSaIiEE19_M_emplace_back_auxIJRKiEEEvDpOT_
	.def	_ZNSt6vectorIiSaIiEE19_M_emplace_back_auxIJRKiEEEvDpOT_;	.scl	2;	.type	32;	.endef
	.set	_ZNSt6vectorIiSaIiEE19_M_emplace_back_auxIJRKiEEEvDpOT_,_ZNSt6vectorIiSaIiEE19_M_emplace_back_auxIIRKiEEEvDpOT_
	.text
	.p2align 4,,15
	.globl	_Z5sievei
	.def	_Z5sievei;	.scl	2;	.type	32;	.endef
	.seh_proc	_Z5sievei
_Z5sievei:
.LFB10023:
	pushq	%r15
	.seh_pushreg	%r15
	pushq	%r14
	.seh_pushreg	%r14
	pushq	%r13
	.seh_pushreg	%r13
	pushq	%r12
	.seh_pushreg	%r12
	pushq	%rbp
	.seh_pushreg	%rbp
	pushq	%rdi
	.seh_pushreg	%rdi
	pushq	%rsi
	.seh_pushreg	%rsi
	pushq	%rbx
	.seh_pushreg	%rbx
	subq	$56, %rsp
	.seh_stackalloc	56
	.seh_endprologue
	cmpl	$1, %ecx
	jle	.L204
	movl	prcnt(%rip), %r11d
	leal	-2(%rcx), %r12d
	leaq	8+vis(%rip), %r13
	leaq	mnp(%rip), %rsi
	xorl	%edi, %edi
	addq	$1, %r12
	movl	%r11d, %ebp
	.p2align 4,,10
.L208:
	movl	0(%r13,%rdi,4), %eax
	leal	2(%rdi), %r8d
	testl	%eax, %eax
	jne	.L206
	leal	1(%r11), %ebp
	leaq	pr(%rip), %rax
	movslq	%ebp, %rdx
	movl	%ebp, %r11d
	movl	%r8d, (%rax,%rdx,4)
	leaq	8+mnp(%rip), %rax
	movl	%r8d, (%rax,%rdi,4)
.L206:
	testl	%r11d, %r11d
	jle	.L210
	movl	4+pr(%rip), %r9d
	movl	%r8d, %eax
	imull	%r9d, %eax
	cmpl	%eax, %ecx
	jl	.L210
	leaq	vis(%rip), %rbx
	cltq
	movl	%r9d, (%rsi,%rax,4)
	movl	$1, (%rbx,%rax,4)
	movl	%r8d, %eax
	cltd
	idivl	%r9d
	testl	%edx, %edx
	je	.L210
	leaq	8+pr(%rip), %r10
	movl	$1, %r9d
	jmp	.L211
	.p2align 4,,10
.L235:
	movl	(%r10), %r14d
	movl	%r14d, %edx
	imull	%r8d, %edx
	cmpl	%edx, %ecx
	jl	.L210
	movslq	%edx, %rdx
	movl	%r8d, %eax
	addq	$4, %r10
	movl	$1, (%rbx,%rdx,4)
	movl	%r14d, (%rsi,%rdx,4)
	cltd
	idivl	%r14d
	testl	%edx, %edx
	je	.L210
.L211:
	addl	$1, %r9d
	cmpl	%r11d, %r9d
	jle	.L235
.L210:
	addq	$1, %rdi
	cmpq	%r12, %rdi
	jne	.L208
	movl	%ebp, prcnt(%rip)
	leaq	48+pfac(%rip), %r15
	leaq	pfac(%rip), %rdi
	leaq	44(%rsp), %rbp
	movl	%ecx, %r12d
	movl	$2, %r14d
.L213:
	movslq	%r14d, %rax
	movl	%r14d, %ebx
	leaq	(%rax,%rax,2), %rax
	leaq	(%rdi,%rax,8), %r13
	.p2align 4,,10
.L219:
	movslq	%ebx, %rax
	movl	(%rsi,%rax,4), %r8d
	movq	8(%r13), %rax
	cmpq	16(%r13), %rax
	movl	%r8d, 44(%rsp)
	je	.L214
	testq	%rax, %rax
	je	.L215
	movl	%r8d, (%rax)
	movl	44(%rsp), %r8d
.L215:
	addq	$4, %rax
	movq	%rax, 8(%r13)
.L216:
	movl	%ebx, %eax
	cltd
	idivl	%r8d
	testl	%edx, %edx
	jne	.L217
	.p2align 4,,10
.L218:
	movl	%ebx, %eax
	cltd
	idivl	%r8d
	cltd
	movl	%eax, %ebx
	idivl	%r8d
	testl	%edx, %edx
	je	.L218
.L217:
	cmpl	$1, %ebx
	jne	.L219
	addl	$1, %r14d
	addq	$24, %r15
	cmpl	%r14d, %r12d
	jge	.L213
.L204:
	addq	$56, %rsp
	popq	%rbx
	popq	%rsi
	popq	%rdi
	popq	%rbp
	popq	%r12
	popq	%r13
	popq	%r14
	popq	%r15
	ret
.L214:
	movq	%rbp, %rdx
	movq	%r15, %rcx
	call	_ZNSt6vectorIiSaIiEE19_M_emplace_back_auxIIRKiEEEvDpOT_
	movl	44(%rsp), %r8d
	jmp	.L216
	.seh_endproc
	.section	.text$_ZNSt8_Rb_treeIiiSt9_IdentityIiESt4lessIiESaIiEE8_M_eraseEPSt13_Rb_tree_nodeIiE,"x"
	.linkonce discard
	.align 2
	.p2align 4,,15
	.globl	_ZNSt8_Rb_treeIiiSt9_IdentityIiESt4lessIiESaIiEE8_M_eraseEPSt13_Rb_tree_nodeIiE
	.def	_ZNSt8_Rb_treeIiiSt9_IdentityIiESt4lessIiESaIiEE8_M_eraseEPSt13_Rb_tree_nodeIiE;	.scl	2;	.type	32;	.endef
	.seh_proc	_ZNSt8_Rb_treeIiiSt9_IdentityIiESt4lessIiESaIiEE8_M_eraseEPSt13_Rb_tree_nodeIiE
_ZNSt8_Rb_treeIiiSt9_IdentityIiESt4lessIiESaIiEE8_M_eraseEPSt13_Rb_tree_nodeIiE:
.LFB10666:
	pushq	%rdi
	.seh_pushreg	%rdi
	pushq	%rsi
	.seh_pushreg	%rsi
	pushq	%rbx
	.seh_pushreg	%rbx
	subq	$32, %rsp
	.seh_stackalloc	32
	.seh_endprologue
	testq	%rdx, %rdx
	movq	%rcx, %rdi
	movq	%rdx, %rbx
	je	.L236
	.p2align 4,,10
.L240:
	movq	24(%rbx), %rdx
	movq	%rdi, %rcx
	call	_ZNSt8_Rb_treeIiiSt9_IdentityIiESt4lessIiESaIiEE8_M_eraseEPSt13_Rb_tree_nodeIiE
	movq	16(%rbx), %rsi
	movq	%rbx, %rcx
	call	_ZdlPv
	testq	%rsi, %rsi
	movq	%rsi, %rbx
	jne	.L240
.L236:
	addq	$32, %rsp
	popq	%rbx
	popq	%rsi
	popq	%rdi
	ret
	.seh_endproc
	.section	.text$_ZNSt8_Rb_treeIiiSt9_IdentityIiESt4lessIiESaIiEE16_M_insert_uniqueIRKiEESt4pairISt17_Rb_tree_iteratorIiEbEOT_,"x"
	.linkonce discard
	.align 2
	.p2align 4,,15
	.globl	_ZNSt8_Rb_treeIiiSt9_IdentityIiESt4lessIiESaIiEE16_M_insert_uniqueIRKiEESt4pairISt17_Rb_tree_iteratorIiEbEOT_
	.def	_ZNSt8_Rb_treeIiiSt9_IdentityIiESt4lessIiESaIiEE16_M_insert_uniqueIRKiEESt4pairISt17_Rb_tree_iteratorIiEbEOT_;	.scl	2;	.type	32;	.endef
	.seh_proc	_ZNSt8_Rb_treeIiiSt9_IdentityIiESt4lessIiESaIiEE16_M_insert_uniqueIRKiEESt4pairISt17_Rb_tree_iteratorIiEbEOT_
_ZNSt8_Rb_treeIiiSt9_IdentityIiESt4lessIiESaIiEE16_M_insert_uniqueIRKiEESt4pairISt17_Rb_tree_iteratorIiEbEOT_:
.LFB10668:
	pushq	%r14
	.seh_pushreg	%r14
	pushq	%r13
	.seh_pushreg	%r13
	pushq	%r12
	.seh_pushreg	%r12
	pushq	%rbp
	.seh_pushreg	%rbp
	pushq	%rdi
	.seh_pushreg	%rdi
	pushq	%rsi
	.seh_pushreg	%rsi
	pushq	%rbx
	.seh_pushreg	%rbx
	subq	$32, %rsp
	.seh_stackalloc	32
	.seh_endprologue
	movq	16(%rdx), %rbx
	movq	%rcx, %r12
	movq	%rdx, %rbp
	movq	%r8, %r13
	leaq	8(%rdx), %r14
	testq	%rbx, %rbx
	je	.L254
	movl	(%r8), %esi
	jmp	.L246
	.p2align 4,,10
.L261:
	movq	16(%rbx), %r10
	movl	$1, %edi
	testq	%r10, %r10
	je	.L260
.L255:
	movq	%r10, %rbx
.L246:
	movl	32(%rbx), %r11d
	cmpl	%esi, %r11d
	jg	.L261
	movq	24(%rbx), %r10
	xorl	%edi, %edi
	testq	%r10, %r10
	jne	.L255
.L260:
	testb	%dil, %dil
	movq	%rbx, %rax
	jne	.L243
	cmpl	%esi, %r11d
	jl	.L251
.L259:
	movq	%rax, (%r12)
	movb	$0, 8(%r12)
.L242:
	movq	%r12, %rax
	addq	$32, %rsp
	popq	%rbx
	popq	%rsi
	popq	%rdi
	popq	%rbp
	popq	%r12
	popq	%r13
	popq	%r14
	ret
.L254:
	movq	%r14, %rbx
	.p2align 4,,10
.L243:
	cmpq	%rbx, 24(%rbp)
	je	.L251
	movq	%rbx, %rcx
	call	_ZSt18_Rb_tree_decrementPSt18_Rb_tree_node_base
	movl	0(%r13), %esi
	movl	32(%rax), %r11d
	cmpl	%esi, %r11d
	jge	.L259
.L251:
	cmpq	%rbx, %r14
	je	.L257
	xorl	%edi, %edi
	movl	32(%rbx), %eax
	cmpl	%eax, 0(%r13)
	setl	%dil
.L249:
	movl	$40, %ecx
	call	_Znwy
	movq	%rax, %rsi
	movl	0(%r13), %eax
	movq	%r14, %r9
	movq	%rbx, %r8
	movq	%rsi, %rdx
	movl	%edi, %ecx
	movl	%eax, 32(%rsi)
	call	_ZSt29_Rb_tree_insert_and_rebalancebPSt18_Rb_tree_node_baseS0_RS_
	addq	$1, 40(%rbp)
	movq	%rsi, (%r12)
	movb	$1, 8(%r12)
	jmp	.L242
.L257:
	movl	$1, %edi
	jmp	.L249
	.seh_endproc
	.section	.text$_ZNSt8_Rb_treeIiiSt9_IdentityIiESt4lessIiESaIiEE4findERKi,"x"
	.linkonce discard
	.align 2
	.p2align 4,,15
	.globl	_ZNSt8_Rb_treeIiiSt9_IdentityIiESt4lessIiESaIiEE4findERKi
	.def	_ZNSt8_Rb_treeIiiSt9_IdentityIiESt4lessIiESaIiEE4findERKi;	.scl	2;	.type	32;	.endef
	.seh_proc	_ZNSt8_Rb_treeIiiSt9_IdentityIiESt4lessIiESaIiEE4findERKi
_ZNSt8_Rb_treeIiiSt9_IdentityIiESt4lessIiESaIiEE4findERKi:
.LFB10680:
	.seh_endprologue
	leaq	8(%rcx), %r8
	movq	16(%rcx), %rcx
	testq	%rcx, %rcx
	je	.L263
	movl	(%rdx), %edx
	movq	%r8, %rax
	jmp	.L266
	.p2align 4,,10
.L274:
	movq	%rcx, %rax
	movq	16(%rcx), %rcx
	testq	%rcx, %rcx
	je	.L273
.L266:
	cmpl	%edx, 32(%rcx)
	jge	.L274
	movq	24(%rcx), %rcx
	testq	%rcx, %rcx
	jne	.L266
.L273:
	cmpq	%rax, %r8
	je	.L263
	cmpl	%edx, 32(%rax)
	jg	.L263
	rep ret
	.p2align 4,,10
.L263:
	movq	%r8, %rax
	ret
	.seh_endproc
	.text
	.p2align 4,,15
	.globl	_Z7calc_LRv
	.def	_Z7calc_LRv;	.scl	2;	.type	32;	.endef
	.seh_proc	_Z7calc_LRv
_Z7calc_LRv:
.LFB10050:
	pushq	%r15
	.seh_pushreg	%r15
	pushq	%r14
	.seh_pushreg	%r14
	pushq	%r13
	.seh_pushreg	%r13
	pushq	%r12
	.seh_pushreg	%r12
	pushq	%rbp
	.seh_pushreg	%rbp
	pushq	%rdi
	.seh_pushreg	%rdi
	pushq	%rsi
	.seh_pushreg	%rsi
	pushq	%rbx
	.seh_pushreg	%rbx
	subq	$200, %rsp
	.seh_stackalloc	200
	.seh_endprologue
	leaq	96(%rsp), %rbx
	leaq	144(%rsp), %rsi
	movl	$0, 104(%rsp)
	movq	$0, 112(%rsp)
	movq	$0, 136(%rsp)
	leaq	8(%rbx), %rax
	movl	$0, 152(%rsp)
	movq	$0, 160(%rsp)
	movq	$0, 184(%rsp)
	movl	$1, 92(%rsp)
	movq	%rax, 120(%rsp)
	movq	%rax, 128(%rsp)
	leaq	8(%rsi), %rax
	movq	%rax, 168(%rsp)
	movq	%rax, 176(%rsp)
	movl	n(%rip), %eax
	testl	%eax, %eax
	jle	.L279
	leaq	64(%rsp), %rdi
	leaq	92(%rsp), %rbp
.L277:
	movq	%rbp, %r8
	movq	%rbx, %rdx
	movq	%rdi, %rcx
.LEHB0:
	call	_ZNSt8_Rb_treeIiiSt9_IdentityIiESt4lessIiESaIiEE16_M_insert_uniqueIRKiEESt4pairISt17_Rb_tree_iteratorIiEbEOT_
	movq	%rbp, %r8
	movq	%rsi, %rdx
	movq	%rdi, %rcx
	call	_ZNSt8_Rb_treeIiiSt9_IdentityIiESt4lessIiESaIiEE16_M_insert_uniqueIRKiEESt4pairISt17_Rb_tree_iteratorIiEbEOT_
.LEHE0:
	movslq	92(%rsp), %rdx
	leaq	lft(%rip), %rcx
	movl	n(%rip), %r12d
	movq	%rdx, %rax
	movl	$1061109567, (%rcx,%rdx,4)
	leaq	rit(%rip), %rcx
	addl	$1, %eax
	cmpl	%eax, %r12d
	movl	$0, (%rcx,%rdx,4)
	movl	%eax, 92(%rsp)
	jge	.L277
	testl	%r12d, %r12d
	movl	$-2, %r14d
	movl	$1, %r15d
	movl	%r12d, %r8d
	jle	.L279
.L304:
	leal	(%r15,%r15), %eax
	movl	%r15d, %r12d
	movq	%rbx, 56(%rsp)
	leal	(%r12,%r15), %ebp
	movl	%eax, %r13d
	movl	$1, %eax
	subl	%r15d, %eax
	cmpl	%r8d, %ebp
	movl	%eax, 52(%rsp)
	jge	.L318
	.p2align 4,,10
.L295:
	movl	52(%rsp), %eax
	leal	1(%rbp), %ecx
	addl	%ebp, %eax
	cmpl	%ecx, %eax
	je	.L319
	leaq	fw(%rip), %rdx
	cltq
	movslq	%ecx, %rcx
	movl	200008(%rdx,%rax,4), %r10d
	movl	200008(%rdx,%rcx,4), %eax
	cmpl	%eax, %r10d
	jle	.L282
	movl	%r10d, %ecx
	movl	%eax, %r10d
	movl	%ecx, %eax
.L282:
	movl	%eax, %ecx
	leal	1(%r10), %r9d
	subl	%r10d, %ecx
	leaq	hib(%rip), %r10
	movslq	%ecx, %rcx
	movslq	%r9d, %r9
	movslq	(%r10,%rcx,4), %rcx
	movl	$1, %r10d
	sall	%cl, %r10d
	imulq	$200005, %rcx, %rcx
	subl	%r10d, %eax
	addl	$1, %eax
	cltq
	leaq	1050024(%rax,%rcx), %rax
	leaq	1050024(%rcx,%r9), %rcx
	movl	12(%rdx,%rcx,4), %edi
	cmpl	%edi, 12(%rdx,%rax,4)
	cmovle	12(%rdx,%rax,4), %edi
.L281:
	cmpl	%r15d, %edi
	movl	%ebp, %edx
	movl	%r12d, %ecx
	cmovg	%r15d, %edi
	movl	%r8d, 40(%rsp)
	movl	%edi, 36(%rsp)
	call	_Z6getlcsii
	cmpl	%r15d, %eax
	movl	40(%rsp), %r8d
	cmovg	%r15d, %eax
	movl	%eax, %ebx
	movl	%eax, 48(%rsp)
	movl	%edi, %eax
	addl	%ebx, %eax
	cmpl	%eax, %r15d
	jg	.L283
	subl	%ebx, %r12d
	movl	36(%rsp), %ebx
	leal	(%r14,%rbp), %eax
	leal	1(%r12), %edi
	movq	%rsi, 40(%rsp)
	leal	1(%rbx,%rax), %eax
	movq	56(%rsp), %rbx
	movl	%eax, %r12d
	movq	112(%rsp), %rax
	testq	%rax, %rax
	je	.L315
	.p2align 4,,10
.L322:
	leaq	8(%rbx), %r8
	jmp	.L287
	.p2align 4,,10
.L321:
	movq	%rax, %r8
	movq	16(%rax), %rax
	testq	%rax, %rax
	je	.L320
.L287:
	cmpl	32(%rax), %edi
	jle	.L321
	movq	24(%rax), %rax
	testq	%rax, %rax
	jne	.L287
.L320:
	leaq	8(%rbx), %rsi
	cmpq	%rsi, %r8
	je	.L315
	movl	32(%r8), %eax
	cmpl	%eax, %r12d
	jl	.L315
	movslq	%eax, %rdx
	leaq	lft(%rip), %rcx
	leal	-1(%r13,%rax), %eax
	movl	%eax, (%rcx,%rdx,4)
	leaq	32(%r8), %rdx
	movq	%rbx, %rcx
	call	_ZNSt8_Rb_treeIiiSt9_IdentityIiESt4lessIiESaIiEE4findERKi
	movq	%rsi, %rdx
	movq	%rax, %rcx
	call	_ZSt28_Rb_tree_rebalance_for_erasePSt18_Rb_tree_node_baseRS_
	movq	%rax, %rcx
	call	_ZdlPv
	movq	112(%rsp), %rax
	subq	$1, 136(%rsp)
	testq	%rax, %rax
	jne	.L322
.L315:
	movl	36(%rsp), %eax
	leal	(%r15,%rbp), %r12d
	subl	48(%rsp), %r12d
	movq	40(%rsp), %rsi
	addl	%ebp, %eax
	movl	%eax, %edi
	movq	160(%rsp), %rax
	testq	%rax, %rax
	je	.L293
	.p2align 4,,10
.L289:
	leaq	8(%rsi), %r8
	jmp	.L292
	.p2align 4,,10
.L324:
	movq	%rax, %r8
	movq	16(%rax), %rax
	testq	%rax, %rax
	je	.L323
.L292:
	cmpl	32(%rax), %r12d
	jle	.L324
	movq	24(%rax), %rax
	testq	%rax, %rax
	jne	.L292
.L323:
	leaq	8(%rsi), %rbx
	cmpq	%rbx, %r8
	je	.L293
	movl	32(%r8), %eax
	cmpl	%eax, %edi
	jl	.L293
	movslq	%eax, %rdx
	leaq	rit(%rip), %rcx
	leal	1(%r14,%rax), %eax
	movl	%eax, (%rcx,%rdx,4)
	leaq	32(%r8), %rdx
	movq	%rsi, %rcx
	call	_ZNSt8_Rb_treeIiiSt9_IdentityIiESt4lessIiESaIiEE4findERKi
	movq	%rbx, %rdx
	movq	%rax, %rcx
	call	_ZSt28_Rb_tree_rebalance_for_erasePSt18_Rb_tree_node_baseRS_
	movq	%rax, %rcx
	call	_ZdlPv
	movq	160(%rsp), %rax
	subq	$1, 184(%rsp)
	testq	%rax, %rax
	jne	.L289
.L293:
	movl	n(%rip), %r8d
.L283:
	movl	%ebp, %r12d
	leal	(%r12,%r15), %ebp
	cmpl	%r8d, %ebp
	jl	.L295
.L318:
	addl	$1, %r15d
	subl	$2, %r14d
	movq	56(%rsp), %rbx
	cmpl	%r8d, %r15d
	jle	.L304
.L279:
	movq	160(%rsp), %rdx
	movq	%rsi, %rcx
	call	_ZNSt8_Rb_treeIiiSt9_IdentityIiESt4lessIiESaIiEE8_M_eraseEPSt13_Rb_tree_nodeIiE
	movq	112(%rsp), %rdx
	movq	%rbx, %rcx
	call	_ZNSt8_Rb_treeIiiSt9_IdentityIiESt4lessIiESaIiEE8_M_eraseEPSt13_Rb_tree_nodeIiE
	nop
	addq	$200, %rsp
	popq	%rbx
	popq	%rsi
	popq	%rdi
	popq	%rbp
	popq	%r12
	popq	%r13
	popq	%r14
	popq	%r15
	ret
	.p2align 4,,10
.L319:
	movl	%r8d, %edi
	subl	%eax, %edi
	addl	$1, %edi
	jmp	.L281
.L301:
	movq	160(%rsp), %rdx
	movq	%rsi, %rcx
	movq	%rax, %rdi
	call	_ZNSt8_Rb_treeIiiSt9_IdentityIiESt4lessIiESaIiEE8_M_eraseEPSt13_Rb_tree_nodeIiE
	movq	112(%rsp), %rdx
	movq	%rbx, %rcx
	call	_ZNSt8_Rb_treeIiiSt9_IdentityIiESt4lessIiESaIiEE8_M_eraseEPSt13_Rb_tree_nodeIiE
	movq	%rdi, %rcx
.LEHB1:
	call	_Unwind_Resume
	nop
.LEHE1:
	.def	__gxx_personality_seh0;	.scl	2;	.type	32;	.endef
	.seh_handler	__gxx_personality_seh0, @unwind, @except
	.seh_handlerdata
.LLSDA10050:
	.byte	0xff
	.byte	0xff
	.byte	0x1
	.uleb128 .LLSDACSE10050-.LLSDACSB10050
.LLSDACSB10050:
	.uleb128 .LEHB0-.LFB10050
	.uleb128 .LEHE0-.LEHB0
	.uleb128 .L301-.LFB10050
	.uleb128 0
	.uleb128 .LEHB1-.LFB10050
	.uleb128 .LEHE1-.LEHB1
	.uleb128 0
	.uleb128 0
.LLSDACSE10050:
	.text
	.seh_endproc
	.def	__main;	.scl	2;	.type	32;	.endef
	.section .rdata,"dr"
.LC0:
	.ascii "%d%s\0"
.LC1:
	.ascii "%d\0"
.LC2:
	.ascii "%d%d\0"
.LC3:
	.ascii "1\0"
.LC4:
	.ascii "2\0"
.LC5:
	.ascii "3\0"
.LC6:
	.ascii "4\0"
.LC7:
	.ascii "-1\0"
	.section	.text.startup,"x"
	.p2align 4,,15
	.globl	main
	.def	main;	.scl	2;	.type	32;	.endef
	.seh_proc	main
main:
.LFB10058:
	pushq	%r15
	.seh_pushreg	%r15
	pushq	%r14
	.seh_pushreg	%r14
	pushq	%r13
	.seh_pushreg	%r13
	pushq	%r12
	.seh_pushreg	%r12
	pushq	%rbp
	.seh_pushreg	%rbp
	pushq	%rdi
	.seh_pushreg	%rdi
	pushq	%rsi
	.seh_pushreg	%rsi
	pushq	%rbx
	.seh_pushreg	%rbx
	subq	$56, %rsp
	.seh_stackalloc	56
	.seh_endprologue
	call	__main
	movl	$200000, %ecx
	call	_Z5sievei
	leaq	8+hib(%rip), %rcx
	leaq	hib(%rip), %r8
	movl	$2, %eax
	.p2align 4,,10
.L326:
	movl	%eax, %edx
	addl	$1, %eax
	addq	$4, %rcx
	sarl	%edx
	movslq	%edx, %rdx
	movl	(%r8,%rdx,4), %edx
	addl	$1, %edx
	movl	%edx, -4(%rcx)
	cmpl	$200001, %eax
	jne	.L326
	leaq	1+str(%rip), %r8
	leaq	n(%rip), %rdx
	leaq	.LC0(%rip), %rcx
	call	_Z5scanfPKcz
	pxor	%xmm1, %xmm1
	cvtsi2sd	n(%rip), %xmm1
	sqrtsd	%xmm1, %xmm0
	ucomisd	%xmm0, %xmm0
	jp	.L365
.L327:
	call	ceil
	cvttsd2si	%xmm0, %eax
	movl	n(%rip), %r9d
	testl	%r9d, %r9d
	movl	%eax, lim(%rip)
	jle	.L333
	leal	-1(%r9), %r8d
	leaq	1+str(%rip), %rdi
	leaq	bk(%rip), %r11
	leaq	1+fw(%rip), %r10
	xorl	%eax, %eax
	addq	$1, %r8
	.p2align 4,,10
.L332:
	movzbl	(%rdi,%rax), %ecx
	movl	%r9d, %edx
	subl	%eax, %edx
	movslq	%edx, %rdx
	movb	%cl, (%r10,%rax)
	addq	$1, %rax
	movb	%cl, (%r11,%rdx)
	cmpq	%r8, %rax
	jne	.L332
.L333:
	leaq	fw(%rip), %rcx
	call	_ZN11SuffixArray4initEv
	leaq	bk(%rip), %rcx
	call	_ZN11SuffixArray4initEv
	call	_Z7calc_LRv
	movl	n(%rip), %r13d
	testl	%r13d, %r13d
	jle	.L331
	leal	-1(%r13), %ebp
	leaq	1+str(%rip), %rdi
	leaq	sum(%rip), %rsi
	xorl	%r8d, %r8d
	xorl	%r11d, %r11d
	movl	$104, %r12d
	addq	$1, %rbp
	.p2align 4,,10
.L335:
	movq	%r12, %r9
	movq	%rsi, %rax
	leal	1(%r11), %ebx
	subq	%r8, %r9
	subq	%r8, %rax
	leaq	(%rsi,%r9), %r10
	.p2align 4,,10
.L334:
	movl	(%rax), %ecx
	leaq	(%rax,%r8), %rdx
	addq	$4, %rax
	cmpq	%r10, %rax
	movl	%ecx, (%rdx,%r9)
	jne	.L334
	movsbl	(%rdi,%r11), %eax
	movslq	%ebx, %rbx
	addq	$1, %r11
	leaq	(%rbx,%rbx,2), %rdx
	subq	$104, %r8
	leaq	(%rbx,%rdx,4), %rdx
	subl	$97, %eax
	cltq
	leaq	(%rax,%rdx,2), %rax
	addl	$1, (%rsi,%rax,4)
	cmpq	%rbp, %r11
	jne	.L335
	leaq	4+st_rit(%rip), %r8
	leaq	4+rit(%rip), %rcx
	salq	$2, %r11
	xorl	%eax, %eax
	.p2align 4,,10
.L336:
	movl	(%rcx,%rax), %edx
	movl	%edx, (%r8,%rax)
	addq	$4, %rax
	cmpq	%r11, %rax
	jne	.L336
.L331:
	leaq	st_rit(%rip), %r10
	leal	2(%r13), %r14d
	xorl	%edi, %edi
	movl	$1, %ebp
	movl	$1, %r12d
	movl	$4, %r15d
.L350:
	movl	%r12d, %r9d
	movl	%ebp, %ecx
	sall	%cl, %r9d
	cmpl	%r9d, %r13d
	jl	.L339
	leal	-1(%rbp), %ecx
	movl	%r12d, %eax
	movq	%r15, %rdx
	movl	%r14d, %ebx
	subq	%rdi, %rdx
	movslq	%ecx, %r11
	sall	%cl, %eax
	subl	%r9d, %ebx
	imulq	$200005, %r11, %r11
	movl	$800020, %ecx
	leal	1(%rax), %r8d
	addq	%r10, %rdx
	addl	%eax, %ebx
	subq	%rdi, %rcx
	.p2align 4,,10
.L337:
	movslq	%r8d, %rsi
	movl	(%rdx), %eax
	leaq	(%rdx,%rdi), %r9
	addq	%r11, %rsi
	cmpl	%eax, (%r10,%rsi,4)
	cmovge	(%r10,%rsi,4), %eax
	addl	$1, %r8d
	addq	$4, %rdx
	cmpl	%ebx, %r8d
	movl	%eax, (%r9,%rcx)
	jne	.L337
.L339:
	addl	$1, %ebp
	subq	$800020, %rdi
	cmpl	$19, %ebp
	jne	.L350
	leaq	qu(%rip), %rdx
	leaq	.LC1(%rip), %rcx
	call	_Z5scanfPKcz
	movl	qu(%rip), %eax
	leal	-1(%rax), %edx
	testl	%eax, %eax
	movl	%edx, qu(%rip)
	je	.L360
	leaq	sum(%rip), %rsi
	leaq	44(%rsp), %rdi
	leaq	40(%rsp), %rbx
.L340:
	leaq	.LC2(%rip), %rcx
	movq	%rdi, %r8
	movq	%rbx, %rdx
	call	_Z5scanfPKcz
	movl	40(%rsp), %ebp
	movslq	44(%rsp), %r11
	leal	-1(%rbp), %ecx
	leaq	(%r11,%r11,2), %rax
	movq	%r11, %r12
	movslq	%ecx, %rcx
	leaq	(%rcx,%rcx,2), %r8
	leaq	(%r11,%rax,4), %rdx
	imulq	$-104, %r11, %r11
	leaq	(%rcx,%r8,4), %r8
	salq	$3, %rdx
	leaq	(%rsi,%rdx), %rax
	leaq	104(%rsi,%rdx), %rdx
	salq	$3, %r8
	jmp	.L342
	.p2align 4,,10
.L367:
	addq	$4, %rax
	cmpq	%rdx, %rax
	je	.L366
.L342:
	leaq	(%rax,%r11), %r10
	movl	(%rax), %r9d
	subl	(%r10,%r8), %r9d
	cmpl	$1, %r9d
	jle	.L367
	movl	%r12d, %edx
	movl	%ebp, %ecx
	call	_Z6check1ii
	testb	%al, %al
	jne	.L368
	movl	%r12d, %edx
	movl	%ebp, %ecx
	call	_Z6check2ii
	testb	%al, %al
	jne	.L369
	movl	%r12d, %edx
	movl	%ebp, %ecx
	call	_Z6check3ii
	testb	%al, %al
	je	.L346
	leaq	.LC5(%rip), %rcx
	call	puts
.L344:
	movl	qu(%rip), %eax
	leal	-1(%rax), %edx
	testl	%eax, %eax
	movl	%edx, qu(%rip)
	jne	.L340
.L360:
	xorl	%eax, %eax
	addq	$56, %rsp
	popq	%rbx
	popq	%rsi
	popq	%rdi
	popq	%rbp
	popq	%r12
	popq	%r13
	popq	%r14
	popq	%r15
	ret
.L366:
	leaq	.LC7(%rip), %rcx
	call	puts
	jmp	.L344
.L368:
	leaq	.LC3(%rip), %rcx
	call	puts
	jmp	.L344
.L346:
	leaq	.LC6(%rip), %rcx
	call	puts
	jmp	.L344
.L369:
	leaq	.LC4(%rip), %rcx
	call	puts
	jmp	.L344
.L365:
	movapd	%xmm1, %xmm0
	call	sqrt
	jmp	.L327
	.seh_endproc
	.p2align 4,,15
	.def	_GLOBAL__sub_I_n;	.scl	3;	.type	32;	.endef
	.seh_proc	_GLOBAL__sub_I_n
_GLOBAL__sub_I_n:
.LFB11207:
	subq	$40, %rsp
	.seh_stackalloc	40
	.seh_endprologue
	leaq	_ZStL8__ioinit(%rip), %rcx
	call	_ZNSt8ios_base4InitC1Ev
	leaq	__tcf_0(%rip), %rcx
	call	atexit
	leaq	pfac(%rip), %rax
	leaq	4800120+pfac(%rip), %rdx
	.p2align 4,,10
.L371:
	movq	$0, (%rax)
	movq	$0, 8(%rax)
	addq	$24, %rax
	movq	$0, -8(%rax)
	cmpq	%rdx, %rax
	jne	.L371
	leaq	__tcf_1(%rip), %rcx
	addq	$40, %rsp
	jmp	atexit
	.seh_endproc
	.section	.ctors,"w"
	.align 8
	.quad	_GLOBAL__sub_I_n
	.globl	_ZZN11SuffixArray5getsaEvE1x
	.section	.data$_ZZN11SuffixArray5getsaEvE1x,"w"
	.linkonce same_size
	.align 64
_ZZN11SuffixArray5getsaEvE1x:
	.space 1600040
	.globl	st_rit
	.bss
	.align 64
st_rit:
	.space 16000400
	.globl	rit
	.align 64
rit:
	.space 800020
	.globl	lft
	.align 64
lft:
	.space 800020
	.globl	sum
	.align 64
sum:
	.space 20800520
	.globl	bk
	.align 64
bk:
	.space 20200508
	.globl	fw
	.align 64
fw:
	.space 20200508
	.globl	_ZGVZN11SuffixArray5getsaEvE1x
	.section	.data$_ZGVZN11SuffixArray5getsaEvE1x,"w"
	.linkonce same_size
	.align 8
_ZGVZN11SuffixArray5getsaEvE1x:
	.space 8
	.globl	pfac
	.bss
	.align 64
pfac:
	.space 4800120
	.globl	mnp
	.align 64
mnp:
	.space 800020
	.globl	vis
	.align 64
vis:
	.space 800020
	.globl	prcnt
	.align 4
prcnt:
	.space 4
	.globl	pr
	.align 64
pr:
	.space 800020
	.globl	str
	.align 64
str:
	.space 200005
	.globl	lim
	.align 4
lim:
	.space 4
	.globl	qu
	.align 4
qu:
	.space 4
	.globl	hib
	.align 64
hib:
	.space 800020
	.globl	n
	.align 4
n:
	.space 4
.lcomm _ZStL8__ioinit,1,1
	.ident	"GCC: (tdm64-1) 4.9.2"
	.def	_ZdlPv;	.scl	2;	.type	32;	.endef
	.def	_ZNSt8ios_base4InitD1Ev;	.scl	2;	.type	32;	.endef
	.def	__mingw_vscanf;	.scl	2;	.type	32;	.endef
	.def	memset;	.scl	2;	.type	32;	.endef
	.def	__cxa_guard_acquire;	.scl	2;	.type	32;	.endef
	.def	__cxa_guard_release;	.scl	2;	.type	32;	.endef
	.def	_Znwy;	.scl	2;	.type	32;	.endef
	.def	_ZSt18_Rb_tree_decrementPSt18_Rb_tree_node_base;	.scl	2;	.type	32;	.endef
	.def	_ZSt29_Rb_tree_insert_and_rebalancebPSt18_Rb_tree_node_baseS0_RS_;	.scl	2;	.type	32;	.endef
	.def	_ZSt28_Rb_tree_rebalance_for_erasePSt18_Rb_tree_node_baseRS_;	.scl	2;	.type	32;	.endef
	.def	_Unwind_Resume;	.scl	2;	.type	32;	.endef
	.def	ceil;	.scl	2;	.type	32;	.endef
	.def	puts;	.scl	2;	.type	32;	.endef
	.def	sqrt;	.scl	2;	.type	32;	.endef
	.def	_ZNSt8ios_base4InitC1Ev;	.scl	2;	.type	32;	.endef
	.def	atexit;	.scl	2;	.type	32;	.endef)");